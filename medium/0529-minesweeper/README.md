# Minesweeper

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Let's play the minesweeper game (Wikipedia, online game)!

You are given an m x n char matrix board representing the game board where:


	'M' represents an unrevealed mine,
	'E' represents an unrevealed empty square,
	'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
	digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
	'X' represents a revealed mine.


You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:


	If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
	If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
	If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
	Return the board when no more squares will be revealed.


 
Example 1:

Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]


Example 2:

Input: board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
Output: [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]


 
Constraints:


	m == board.length
	n == board[i].length
	1 <= m, n <= 50
	board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
	click.length == 2
	0 <= clickr < m
	0 <= clickc < n
	board[clickr][clickc] is either 'M' or 'E'.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.7 MB  
**Submitted:** 2026-08-10T16:43:29.614Z  

```cpp
        if(mines>0){
            board[r][c]='0'+mines;
            return;
        }
        for(int i=0;i<8;i++){
            int n_r=r+d_row[i];
            int n_c=r+d_col[i];
            if(n_r<n && n_r>=0 && n_c>=0 && n_c<m && vis[n_r][n_c]==0){
                dfs(n_r,n_c,board);
            }
        }
    }

        board[r][c]='B';
        }
            }
                mines++;
            if(n_r<n && n_r>=0 && n_c>=0 && n_c<m && board[n_r][n_c]=='M'){
            int n_c=r+d_col[i];
        return;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        cr=click[0];
        cc=click[1];
        n=board.size();
        m=board[0].size();
        if(board[cr][cc]=='M'){
            board[cr][cc]='X';
            return board;
        }
        vis.assign(n,vector<int>(m,0));
        dfs(cr,cc,board);
        return board;
    }

```

---

[View on LeetCode](https://leetcode.com/problems/minesweeper/)