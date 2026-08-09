# 01 Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 
Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]


Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]


 
Constraints:


	m == mat.length
	n == mat[i].length
	1 <= m, n <= 104
	1 <= m * n <= 104
	mat[i][j] is either 0 or 1.
	There is at least one 0 in mat.


 
Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

## Solution

**Language:** C++  
**Runtime:** 28 ms (beats 23.35%)  
**Memory:** 41.7 MB (beats 8.83%)  
**Submitted:** 2026-08-09T12:34:37.080Z  

```cpp
class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> dis;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vis.assign(n,vector<int>(m,0));
        dis.assign(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    dis[i][j]=0;
                }
            }
        }

        vector<int>d_row={-1,1,0,0};
        vector<int>d_col={0,0,-1,1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int distance=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int new_row=r+d_row[i];
                int new_col=c+d_col[i];
                if(new_row<n && new_row>=0 && new_col<m && new_col>=0 && !vis[new_row][new_col]){
                    dis[new_row][new_col]=distance+1;
                    vis[new_row][new_col]=1;
                    q.push({{new_row,new_col},distance+1});
                }
            }
        }
        return dis;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/01-matrix/)