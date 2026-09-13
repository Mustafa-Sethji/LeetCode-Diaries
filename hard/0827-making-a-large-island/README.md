# Making A Large Island

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 
Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.


Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.


 
Constraints:


	n == grid.length
	n == grid[i].length
	1 <= n <= 500
	grid[i][j] is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 87 ms  
**Memory:** 55.9 MB  
**Submitted:** 2026-09-13T05:14:20.042Z  

```cpp
class Solution {
public:
    int n;
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis,int &label){
        if(i>=n || j>=n || i<0 || j<0 || vis[i][j] || grid[i][j]==0) return 0;
        vis[i][j]=true;
        grid[i][j]=label;
        int siz=1;
        for(auto &dir:directions){
            int nrow=dir[0]+i;
            int ncol=dir[1]+j;
            siz+=dfs(nrow,ncol,grid,vis,label);
        }
        return siz;

    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int maxArea=0;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        unordered_map<int,int>mp;
        int label=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area=dfs(i,j,grid,visited,label);
                    maxArea=max(maxArea,area);
                    mp[label]=area;
                    label++;
                }
            }
        }
        if(maxArea==0)return 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vector<int>vis(label,0);
                    int area=1;
                    for(auto &dir:directions){
                        int nrow=dir[0]+i;
                        int ncol=dir[1]+j;
                        if(nrow<0 || ncol<0 || nrow>=n || ncol>=n || grid[nrow][ncol]==0)continue;
                        int labl=grid[nrow][ncol];
                        if( grid[nrow][ncol]!=0 && !vis[labl]){
                            vis[labl]=1;
                            area+=mp[labl];
                        }
                    }
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/making-a-large-island/)