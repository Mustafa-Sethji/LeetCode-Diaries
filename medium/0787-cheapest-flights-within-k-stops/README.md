# Cheapest Flights Within K Stops

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 
Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.


Example 2:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.


Example 3:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.


 
Constraints:


	2 <= n <= 100
	0 <= flights.length <= (n * (n - 1) / 2)
	flights[i].length == 3
	0 <= fromi, toi < n
	fromi != toi
	1 <= pricei <= 104
	There will not be any multiple flights between two cities.
	0 <= src, dst, k < n
	src != dst

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.6 MB  
**Submitted:** 2026-09-11T06:58:40.826Z  

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto it:flights){
            mp[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;//stops,node,cost
        q.push({0,{src,0}});
        while(!q.empty()){
            int curr_stops=q.front().first;
            int curr_node=q.front().second.first;
            int curr_dist=q.front().second.second;
            q.pop();
            for(auto it:mp[curr_node]){
                int node=it.first;
                int new_dist=it.second+curr_dist;
                if(curr_stops+1<=k+1 && new_dist<dist[node]){
                    dist[node]=new_dist;
                    q.push({curr_stops+1,{node,new_dist}});
                }
            }
        }

        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/cheapest-flights-within-k-stops/)