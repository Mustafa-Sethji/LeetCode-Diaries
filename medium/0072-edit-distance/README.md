# Edit Distance

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:


	Insert a character
	Delete a character
	Replace a character


 
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')


Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


 
Constraints:


	0 <= word1.length, word2.length <= 500
	word1 and word2 consist of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.9 MB (beats 82.38%)  
**Submitted:** 2026-08-04T10:32:38.511Z  

```cpp
class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s1,string &s2,int i,int j){
        if(i<0)return j+1;
        if(j<0)return i+1;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,i-1,j-1);

        return dp[i][j]=1+min(solve(s1,s2,i-1,j),//delete
                            min(solve(s1,s2,i-1,j-1),//replace
                                solve(s1,s2,i,j-1)//insert
                                )
                            );
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.assign(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/edit-distance/)