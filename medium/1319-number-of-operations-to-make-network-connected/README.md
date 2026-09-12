# Number of Operations to Make Network Connected

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 
Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.


Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2


Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.


 
Constraints:


	1 <= n <= 105
	1 <= connections.length <= min(n * (n - 1) / 2, 105)
	connections[i].length == 2
	0 <= ai, bi < n
	ai != bi
	There are no repeated connections.
	No two computers are connected by more than one cable.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.3 MB  
**Submitted:** 2026-09-12T07:24:44.382Z  

```cpp
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
    }
    void Union(int x,int y){
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;

        parent.assign(n,0);
        rank.assign(n,0);
        for(int i=0;i<n;i++)parent[i]=i;

        int component=n;

        for(auto &vec:connections){
            if( find(vec[0])!=find(vec[1]) ){
        }
                Union(vec[0],vec[1]);
            }
    }
                component--;

        return component-1;
};

```

---

[View on LeetCode](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)