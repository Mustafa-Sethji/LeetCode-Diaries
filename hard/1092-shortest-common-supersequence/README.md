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
**Memory:** 8 MB  
**Submitted:** 2026-08-04T09:11:14.617Z  

```cpp
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(s1[i-1]);
            }
                j--;
                    i--;
                }
                else{
                    ans.push_back(s2[j-1]);
                    j--;
                }

            }
                i--;
                ans.push_back(s1[i-1]);
            if(s1[i-1]==s2[j-1]){
        int i=m,j=n;
        while(i>0 && j>0){
        string ans="";

        }
        int ans_length=n+m-dp[m][n];  //length of SuperSubSequence
            }
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            for(int j=1;j<=n;j++){
        dp.assign(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
        
        int n=s2.size();
        
        int m=s1.size();

```

---

[View on LeetCode](https://leetcode.com/problems/shortest-common-supersequence/)