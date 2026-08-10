# Max Area of Island

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 
Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.


Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0


 
Constraints:


	m == grid.length
	n == grid[i].length
	1 <= m, n <= 50
	grid[i][j] is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.7 MB  
**Submitted:** 2026-08-10T02:05:49.878Z  

```cpp

        return area;
        }
            }
                }
                    vis[n_row][n_col]=1;
                    q.push({n_row,n_col});
                grid[n_row][n_col]==1){
                if(n_row<n && n_row>=0 && n_col<m && n_col>=0 && !vis[n_row][n_col] && 
                int n_row=row+d_row[i];
                int n_col=col+d_col[i];
            area++;
            for(int i=0;i<4;i++){
            int col=q.front().second;
            q.pop();
        while(!q.empty()){
            int row=q.front().first;
        q.push({r,c});
        vis[r][c]=1;
        int area=0;
    vector<int>d_col={0,0,1,-1};
    int bfs(int r,int c,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
public:
    int n,m;
    vector<vector<int>>vis;
    vector<int>d_row={-1,1,0,0};
class Solution {

```

---

[View on LeetCode](https://leetcode.com/problems/max-area-of-island/)