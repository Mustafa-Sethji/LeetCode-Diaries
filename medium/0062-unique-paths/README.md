# Unique Paths

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 
Example 1:

Input: m = 3, n = 7
Output: 28


Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


 
Constraints:


	1 <= m, n <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.5 MB (beats 5.23%)  
**Submitted:** 2026-09-08T17:06:23.704Z  

```cpp
class Solution {
public:
    int countpath(int i,int j,int row,int col,vector<vector<int>>&dp){
        if(i==row-1 && j==col-1) return 1;
        if(i>=row || j>=col) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j]=countpath(i,j+1,row,col,dp)+countpath(i+1,j,row,col,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return countpath(0,0,m,n,dp);
    
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/unique-paths/)