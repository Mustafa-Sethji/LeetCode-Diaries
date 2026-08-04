# Distinct Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 
Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit


Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

 
Constraints:


	1 <= s.length, t.length <= 1000
	s and t consist of English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-08-04T10:25:41.123Z  

```cpp
class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    string s1;
    string s2;
    int solve(int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i]==s2[j])return solve(i-1,j)+solve(i-1,j-1);
        return solve(i-1,j);
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        dp.assign(m,vector<int>(n,-1));
        s1=s;
        s2=t;
        return solve(m-1,n-1);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/distinct-subsequences/)