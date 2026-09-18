# Number of Closed Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An *island* is a maximal 4-directionally connected group of `0s` and a *closed island* is an island **totally** (all left, top, right, bottom) surrounded by `1s.`

Return the number of *closed islands*.

 

**Example 1:**

```
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

**Example 2:**

```
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

```

**Example 3:**

```
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

```

 

**Constraints:**

- 1 <= grid.length, grid[0].length <= 100
- 0 <= grid[i][j] <=1

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 13.9 MB (beats 41.60%)  
**Submitted:** 2026-09-18T08:23:39.725Z  

```cpp
class Solution {
public:
    int n,m;

    bool dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){

        if( r>=n || r<0 || c<0 || c>=m )return false;

        if(grid[r][c]==1)
            return true;
        if(vis[r][c])
            return true;

        vis[r][c]=1;

        bool left_bound=dfs(r,c-1,vis,grid);
        bool right_bound=dfs(r,c+1,vis,grid);
        bool up_bound=dfs(r-1,c,vis,grid);
        bool down_bound=dfs(r+1,c,vis,grid);

        return (left_bound && right_bound && up_bound && down_bound); 
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int region=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && !vis[i][j]  && dfs(i,j,vis,grid) )region++;
            }
        }
        return region;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-closed-islands/)