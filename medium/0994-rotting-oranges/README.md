# Rotting Oranges

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an m x n grid where each cell can have one of three values:


	0 representing an empty cell,
	1 representing a fresh orange, or
	2 representing a rotten orange.


Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 
Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4


Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


 
Constraints:


	m == grid.length
	n == grid[i].length
	1 <= m, n <= 10
	grid[i][j] is 0, 1, or 2.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 16.7 MB (beats 70.31%)  
**Submitted:** 2026-08-09T08:19:04.407Z  

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_orange=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh_orange++;
            }
        }
        if(fresh_orange==0)return 0;
        int minutes=0;
        vector<int>d_row={-1,0,1,0};
        vector<int>d_col={0,1,0,-1};
        while(!q.empty() && fresh_orange>0){
            int qsize=q.size();
            while(qsize--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int new_row=r+d_row[i];
                    int new_col=c+d_col[i];
                    if(new_row<n && new_row>-1 && new_col<m && new_col>-1){
                        if(grid[new_row][new_col]==1){
                            fresh_orange--;
                            q.push({new_row,new_col});
                            grid[new_row][new_col]=2;
                        }
                    }
                } 
            }
            minutes++;           
        }

        if(fresh_orange==0)return minutes;
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/rotting-oranges/)