# Count Square Submatrices with All Ones

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 
Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.


Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.


 
Constraints:


	1 <= arr.length <= 300
	1 <= arr[0].length <= 300
	0 <= arr[i][j] <= 1

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 64.09%)  
**Memory:** 30.4 MB (beats 50.06%)  
**Submitted:** 2026-09-08T18:07:46.513Z  

```cpp
class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int m;
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(i>=n || j>=m)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(matrix[i][j]==0)return 0;

        int right=solve(i,j+1,matrix);
        int down=solve(i+1,j,matrix);
        int diag=solve(i+1,j+1,matrix);

        return dp[i][j]=1+min(min(right,down),diag);
    }
    int countSquares(vector<vector<int>>& matrix) {
        
        n=matrix.size();
        m=matrix[0].size();
        int ans=0;
        dp.assign(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=solve(i,j,matrix);
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)