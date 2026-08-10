# Maximum Number of Fish in a Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:


	A land cell if grid[r][c] = 0, or
	A water cell containing grid[r][c] fish, if grid[r][c] > 0.


A fisher can start at any water cell (r, c) and can do the following operations any number of times:


	Catch all the fish at cell (r, c), or
	Move to any adjacent water cell.


Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 
Example 1:

Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.


Example 2:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 


 
Constraints:


	m == grid.length
	n == grid[i].length
	1 <= m, n <= 10
	0 <= grid[i][j] <= 10

## Solution

**Language:** C++  
**Runtime:** 159 ms (beats 5.00%)  
**Memory:** 186.9 MB (beats 5.00%)  
**Submitted:** 2026-08-10T17:54:42.738Z  

```cpp
class Solution {
public:
    int n,m;
    vector<vector<int>>vis;
    vector<int>d_row={-1,1,0,0};
    vector<int>d_col={0,0,1,-1};
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                queue<pair<pair<int,int>,int>>q;
                vis.assign(n,vector<int>(m,0));
                if(grid[i][j]==0) continue;
                q.push({{i,j},grid[i][j]});
                vis[i][j]=1;
                int fish=0;
                while(!q.empty()){
                    int r=q.front().first.first;
                    int c=q.front().first.second;
                    int fish_in=q.front().second;
                    q.pop();
                    fish+=fish_in;
                    for(int k=0;k<4;k++){
                        int n_r=r+d_row[k];
                        int n_c=c+d_col[k];
                        if(n_r<n && n_r>=0 && n_c>=0 && n_c<m && vis[n_r][n_c]==0 && grid[n_r][n_c]>0){
                            q.push({{n_r,n_c},grid[n_r][n_c]});
                            vis[n_r][n_c]=1;
                        }
                    }
                }
                ans=max(ans,fish);
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/)