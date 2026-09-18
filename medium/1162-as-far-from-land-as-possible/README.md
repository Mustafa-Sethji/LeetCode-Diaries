# As Far from Land as Possible

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `n x n` `grid` containing only values `0` and `1`, where `0` represents water and `1` represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return `-1`.

The distance used in this problem is the Manhattan distance: the distance between two cells `(x0, y0)` and `(x1, y1)` is `|x0 - x1| + |y0 - y1|`.

 

**Example 1:**

```
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

```

**Example 2:**

```
Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

```

 

**Constraints:**

- n == grid.length
- n == grid[i].length
- 1 <= n <= 100
- grid[i][j] is 0 or 1

## Solution

**Language:** C++  
**Runtime:** 21 ms (beats 31.70%)  
**Memory:** 25.5 MB (beats 55.37%)  
**Submitted:** 2026-09-18T07:32:36.231Z  

```cpp
class Solution {
public:

    vector<int>del_row={0,0,1,-1};
    vector<int>del_col={-1,1,0,0};

    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        //vector<vector<int>>vis(n,vector<int>(n,0));

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                    //vis[i][j]=1;
                }
            }
        }

        if(q.empty() || q.size()==n*n)return -1;

        while(!q.empty()){
            int k=q.size();
            while(k--){

                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int r_=row+del_row[i];
                    int c_=col+del_col[i];
                    if(r_<n && r_>=0 && c_<n && c_>=0 && dist[r_][c_]>dist[row][col]+1){
                        dist[r_][c_]=dist[row][col]+1;
                        q.push({r_,c_});
                    }
                }

            }
        }


        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,*max_element(dist[i].begin(),dist[i].end()));
        } 
        return maxi;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/as-far-from-land-as-possible/)