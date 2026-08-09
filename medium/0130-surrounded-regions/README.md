# Surrounded Regions

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:


	Connect: A cell is connected to adjacent cells horizontally or vertically.
	Region: To form a region connect every 'O' cell.
	Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.


To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 
Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.


Example 2:


Input: board = [["X"]]

Output: [["X"]]


 
Constraints:


	m == board.length
	n == board[i].length
	1 <= m, n <= 200
	board[i][j] is 'X' or 'O'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 14.6 MB (beats 36.39%)  
**Submitted:** 2026-08-09T13:09:48.080Z  

```cpp
class Solution {
public:
    vector<int>d_row={-1,1,0,0};
    vector<int>d_col={0,0,1,-1};
    vector<vector<int>>vis;
    int n,m;
    void dfs(int r,int c,vector<vector<char>>& board){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int n_r=r+d_row[i];
            int n_c=c+d_col[i];
            if(n_c<m && n_c>=0 && n_r>=0 && n_r<n && !vis[n_r][n_c] && board[n_r][n_c]=='O')dfs(n_r,n_c,board);
        }
        return ;
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(!vis[i][j] && board[i][j]=='O'){
                        dfs(i,j,board);
                    }
                }
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && board[i][j]=='O')board[i][j]='X';
            }
        }
        return ;
    }

};
```

---

[View on LeetCode](https://leetcode.com/problems/surrounded-regions/)