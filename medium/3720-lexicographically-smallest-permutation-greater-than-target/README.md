# Lexicographically Smallest Permutation Greater Than Target

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two strings s and target, both having length n, consisting of lowercase English letters.

Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

 
Example 1:


Input: s = "abc", target = "bba"

Output: "bca"

Explanation:


	The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
	The lexicographically smallest permutation that is strictly greater than target is "bca".



Example 2:


Input: s = "leet", target = "code"

Output: "eelt"

Explanation:


	The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
	The lexicographically smallest permutation that is strictly greater than target is "eelt".



Example 3:


Input: s = "baba", target = "bbaa"

Output: ""

Explanation:


	The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
	None of them is lexicographically strictly greater than target. Therefore, the answer is "".



 
Constraints:


	1 <= s.length == target.length <= 300
	s and target consist of only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.1 MB (beats 48.41%)  
**Submitted:** 2026-08-27T01:38:45.234Z  

```cpp
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int i = 0;

        while (i < n && freq[target[i] - 'a'] > 0) {
            freq[target[i] - 'a']--;
            i++;
        }

        for (int pos = i; pos >= 0; pos--) {
            if (pos < i) {
                freq[target[pos] - 'a']++;
            }

            if (pos == n) {
                continue;
            }

            int x = target[pos] - 'a';

            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    string ans;

                    ans += target.substr(0, pos);

                    ans += char('a' + j);
                    freq[j]--;

                    for (int k = 0; k < 26; k++) {
                        ans += string(freq[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/)