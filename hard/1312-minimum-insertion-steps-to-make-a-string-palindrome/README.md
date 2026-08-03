# Minimum Insertion Steps to Make a String Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 
Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.


Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".


Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".


 
Constraints:


	1 <= s.length <= 500
	s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 31 ms (beats 63.76%)  
**Memory:** 31.4 MB (beats 71.50%)  
**Submitted:** 2026-08-03T15:27:34.612Z  

```cpp
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,string &s){
        if(i>=j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s);

        int inc_i=1+solve(i+1,j,s);
        int dec_j=1+solve(i,j-1,s);

        return dp[i][j]=min(inc_i,dec_j);
    }
    int minInsertions(string s) {
        int n=s.size();
        dp.assign(n, vector<int>(n,-1));
        int maxi=0;
        return solve(0,s.size()-1,s);
        // for(int i=0;i<s.size();i++){
        //     for(int j=0;j<s.size();j++){
        //         maxi=max(maxi,dp[i][j]);
        //     }
        // }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)