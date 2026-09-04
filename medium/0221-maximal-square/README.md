# Maximal Square

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 
Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4


Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1


Example 3:

Input: matrix = [["0"]]
Output: 0


 
Constraints:


	m == matrix.length
	n == matrix[i].length
	1 <= m, n <= 300
	matrix[i][j] is '0' or '1'.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.6 MB  
**Submitted:** 2026-09-04T06:23:24.338Z  

```cpp
class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    int solve(int i,int j,vector<vector<char>>& matrix){
        if(i>=n || j>=m)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        // if(matrix[i][j] == '0')return dp[i][j] = 0;

        int right=solve(i,j+1,matrix);
        int below=solve(i+1,j+1,matrix);
        int left=solve(i+1,j,matrix);

        return dp[i][j]=(matrix[i][j]-'0')+min(right,min(below,left));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.assign(n,vector<int>(m,-1));
        solve(0,0,matrix);
        int maxside=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxside=max(maxside,dp[i][j]);
            }
        }
        return maxside*maxside;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximal-square/)