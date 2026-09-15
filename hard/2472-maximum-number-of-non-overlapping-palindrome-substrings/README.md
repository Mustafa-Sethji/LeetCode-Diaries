# Maximum Number of Non-overlapping Palindrome Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s` and a **positive** integer `k`.

Select a set of **non-overlapping** substrings from the string `s` that satisfy the following conditions:

- The length of each substring is at least k.
- Each substring is a palindrome.

Return *the **maximum** number of substrings in an optimal selection*.

A **substring** is a contiguous sequence of characters within a string.

 

**Example 1:**

```
Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.

```

**Example 2:**

```
Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.

```

 

**Constraints:**

- 1 <= k <= s.length <= 2000
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 182 ms (beats 43.72%)  
**Memory:** 19.7 MB (beats 32.72%)  
**Submitted:** 2026-09-15T09:07:18.755Z  

```cpp
class Solution {
public:
    int n, k;
    vector<vector<bool>> pal;
    vector<int> dp;

    int solve(int i, string &s) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = solve(i + 1, s);

        for (int j = i + k - 1; j < n; j++) {
            if (pal[i][j]) {
                ans = max(ans, 1 + solve(j + 1, s));
            }
        }

        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {
        n = s.size();
        this->k = k;

        pal.assign(n, vector<bool>(n, false));
        dp.assign(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        return solve(0, s);
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)