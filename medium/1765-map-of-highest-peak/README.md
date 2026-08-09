# Map of Highest Peak

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer matrix isWater of size m x n that represents a map of land and water cells.


	If isWater[i][j] == 0, cell (i, j) is a land cell.
	If isWater[i][j] == 1, cell (i, j) is a water cell.


You must assign each cell a height in a way that follows these rules:


	The height of each cell must be non-negative.
	If the cell is a water cell, its height must be 0.
	Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).


Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 
Example 1:



Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.


Example 2:



Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.


 
Constraints:


	m == isWater.length
	n == isWater[i].length
	1 <= m, n <= 1000
	isWater[i][j] is 0 or 1.
	There is at least one water cell.


 
Note: This question is the same as 542: https://leetcode.com/problems/01-matrix/

## Solution

**Language:** C++  
**Runtime:** 96 ms (beats 23.18%)  
**Memory:** 135.8 MB (beats 9.85%)  
**Submitted:** 2026-08-09T12:43:30.897Z  

```cpp
class Solution {
public:
    vector<vector<int>>vis;
    vector<vector<int>>dis;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vis.assign(n,vector<int>(m,0));
        dis.assign(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    vis[i][j]=1;
                    dis[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }

        vector<int>d_row={-1,1,0,0};
        vector<int>d_col={0,0,1,-1};

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

[View on LeetCode](https://leetcode.com/problems/map-of-highest-peak/)