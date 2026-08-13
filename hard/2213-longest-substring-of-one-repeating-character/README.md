# Longest Substring of One Repeating Character

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.

The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.

 
Example 1:

Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation: 
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc". 
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].


Example 2:

Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
Explanation:
- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].


 
Constraints:


	1 <= s.length <= 105
	s consists of lowercase English letters.
	k == queryCharacters.length == queryIndices.length
	1 <= k <= 105
	queryCharacters consists of lowercase English letters.
	0 <= queryIndices[i] < s.length

## Solution

**Language:** C++  
**Runtime:** 329 ms (beats 33.56%)  
**Memory:** 112.9 MB (beats 33.56%)  
**Submitted:** 2026-08-13T10:35:38.972Z  

```cpp
class Solution {
public:
    struct Node {
        int len;       // length of segment
        int pref;      // longest same-character prefix
        int suff;      // longest same-character suffix
        int best;      // longest same-character substring
        char leftChar;
        char rightChar;

        Node() {
            len = pref = suff = best = 0;
            leftChar = rightChar = '#';
        }

        Node(char c) {
            len = pref = suff = best = 1;
            leftChar = rightChar = c;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;

        // If the whole left segment has the same character
        // as the beginning of the right segment
        if (a.pref == a.len && a.rightChar == b.leftChar)
            res.pref = a.len + b.pref;

        // If the whole right segment has the same character
        // as the end of the left segment
        if (b.suff == b.len && a.rightChar == b.leftChar)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        // Join suffix of left + prefix of right
        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            seg[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-substring-of-one-repeating-character/)