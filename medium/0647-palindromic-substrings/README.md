# Palindromic Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 
Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


 
Constraints:


	1 <= s.length <= 1000
	s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 43 ms (beats 22.57%)  
**Memory:** 34.7 MB (beats 14.44%)  
**Submitted:** 2026-09-04T07:19:00.729Z  

```cpp
class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string& s) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] != s[j])
            return dp[i][j] = false;

        return dp[i][j] = solve(i + 1, j - 1, s);
    }

    int countSubstrings(string s) {
        int n = s.size();

        dp.assign(n, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(i, j, s))
                    ans++;
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindromic-substrings/)