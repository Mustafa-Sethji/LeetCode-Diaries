# Number of Matching Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.


	For example, "ace" is a subsequence of "abcde".


 
Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".


Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2


 
Constraints:


	1 <= s.length <= 5 * 104
	1 <= words.length <= 5000
	1 <= words[i].length <= 50
	s and words[i] consist of only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 215 ms (beats 21.34%)  
**Memory:** 55.6 MB (beats 58.74%)  
**Submitted:** 2026-08-28T18:01:27.929Z  

```cpp
class Solution {
public:
    unordered_map<char,vector<int>>hash;
    bool solve(string &s,string &sub){
        int prev=-1;
        for(int i=0;i<sub.size();i++){
            if(hash.find(sub[i])!=hash.end()){
                auto it=upper_bound(hash[sub[i]].begin(),hash[sub[i]].end(),prev);

                if(it==hash[sub[i]].end()) return false;

                prev=*it;
            }
            else return false;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=words.size();
        int count=0;

        for(int i=0;i<s.size();i++){
            hash[s[i]].push_back(i);
        }

        for(int i=0;i<n;i++){
            if(solve(s,words[i])){
                count++;
                cout<<words[i]<<"\n";
            }
        }
        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-matching-subsequences/)