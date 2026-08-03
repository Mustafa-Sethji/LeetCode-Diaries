# Shortest Common Supersequence

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 
Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.


Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"


 
Constraints:


	1 <= str1.length, str2.length <= 1000
	str1 and str2 consist of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-08-03T15:50:51.392Z  

```cpp
    vector<vector<bool>> vis;
    string solve(string &s1,string &s2,int i,int j){
        if(i==s1.size() || j==s2.size())return s1.substr(i)+s2.substr(j);

        if(vis[i][j])return dp[i][j];

        vis[i][j]=true;

        if(s1[i]==s2[j]){
            return dp[i][j]=string(1, s1[i])+solve(s1,s2,i+1,j+1);
        }
        else {
            string first=string(1,s1[i])+solve(s1,s2,i+1,j);
            string second=string(1,s2[j])+solve(s1,s2,i,j+1);
            if(first.size()<second.size())return dp[i][j]=first;
            else return dp[i][j]=second;
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vis.assign(n,vector<bool>(m,false));
        dp.assign(n,vector<string>(m,"#"));

        return solve(str1,str2,0,0);
    }

};
    vector<vector<string>>dp;
public:
class Solution {

```

---

[View on LeetCode](https://leetcode.com/problems/shortest-common-supersequence/)