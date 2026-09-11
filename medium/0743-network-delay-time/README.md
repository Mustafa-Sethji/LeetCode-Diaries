# Network Delay Time

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 
Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2


Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1


Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1


 
Constraints:


	1 <= k <= n <= 100
	1 <= times.length <= 6000
	times[i].length == 3
	1 <= ui, vi <= n
	ui != vi
	0 <= wi <= 100
	All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

## Solution

**Language:** C++  
**Runtime:** 4 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-09-11T06:25:40.149Z  

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto it:times){
            mp[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>q;
        vector<int>dist(n+1,INT_MAX);
        q.push({k,0});
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            for(auto it:mp[node]){
                int curr=it.first;
                int new_time=time+it.second;
                if(curr<n+1 && dist[curr]>new_time){
                    dist[curr]=new_time;
                    q.push({curr,new_time});
                }
            }
        }
        int mx=*max_element(dist.begin()+1,dist.end());
        if(mx==INT_MAX)return -1;
        return mx;
    }
        dist[k]=0;
};

```

---

[View on LeetCode](https://leetcode.com/problems/network-delay-time/)