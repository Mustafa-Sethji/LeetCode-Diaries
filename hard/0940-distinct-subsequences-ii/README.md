# Distinct Subsequences II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
 
Example 1:

Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".


Example 2:

Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".


Example 3:

Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".


 
Constraints:


	1 <= s.length <= 2000
	s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 23.13%)  
**Memory:** 10.2 MB (beats 11.37%)  
**Submitted:** 2026-09-07T02:59:21.583Z  

```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> dp;

    long long solve(int i, string &s, vector<int> &prev) {
        if (i < 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        long long ans = (2LL * solve(i - 1, s, prev)) % MOD;

        if (prev[i] != -1) {
            ans -= solve(prev[i] - 1, s, prev);
            ans = (ans + MOD) % MOD;
        }

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> prev(n, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            prev[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }

        dp.assign(n, -1);

        return (solve(n - 1, s, prev) - 1 + MOD) % MOD;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/distinct-subsequences-ii/)