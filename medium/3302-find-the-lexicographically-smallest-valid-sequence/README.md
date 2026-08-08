# Find the Lexicographically Smallest Valid Sequence

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two strings word1 and word2.

A string x is called almost equal to y if you can change at most one character in x to make it identical to y.

A sequence of indices seq is called valid if:


	The indices are sorted in ascending order.
	Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.


Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.

Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.

 
Example 1:


Input: word1 = "vbcca", word2 = "abc"

Output: [0,1,2]

Explanation:

The lexicographically smallest valid sequence of indices is [0, 1, 2]:


	Change word1[0] to 'a'.
	word1[1] is already 'b'.
	word1[2] is already 'c'.



Example 2:


Input: word1 = "bacdc", word2 = "abc"

Output: [1,2,4]

Explanation:

The lexicographically smallest valid sequence of indices is [1, 2, 4]:


	word1[1] is already 'a'.
	Change word1[2] to 'b'.
	word1[4] is already 'c'.



Example 3:


Input: word1 = "aaaaaa", word2 = "aaabc"

Output: []

Explanation:

There is no valid sequence of indices.


Example 4:


Input: word1 = "abc", word2 = "ab"

Output: [0,1]


 
Constraints:


	1 <= word2.length < word1.length <= 3 * 105
	word1 and word2 consist only of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 40 ms (beats 72.34%)  
**Memory:** 109.3 MB (beats 46.81%)  
**Submitted:** 2026-08-08T10:54:21.571Z  

```cpp
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word2.size();
        vector<int>last(n,-1);
        int j=n-1;
        for(int i=word1.size()-1;i>=0;i--){
            if(j>=0 && word1[i]==word2[j]){
                last[j]=i;
                j--;
            }
        }
        j=0;
        int flag=1;
        vector<int>ans;
        for(int i=0;i<word1.size();i++){
            if(j<n){
                if(word1[i]==word2[j] || (flag==1 && (j==n-1 || i+1<=last[j+1]))){
                    if(word1[i]!=word2[j]){
                        flag=0;
                    }
                    ans.push_back(i);
                    j++;
                }
            }
        }
        return (j==n) ? ans : vector<int>();
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/)