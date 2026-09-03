# Word Break

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 
Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.


Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


 
Constraints:


	1 <= s.length <= 300
	1 <= wordDict.length <= 1000
	1 <= wordDict[i].length <= 20
	s and wordDict[i] consist of only lowercase English letters.
	All the strings of wordDict are unique.

## Solution

**Language:** C++  
**Runtime:** 18 ms (beats 15.59%)  
**Memory:** 18.5 MB (beats 16.09%)  
**Submitted:** 2026-09-03T17:25:25.599Z  

```cpp
class Solution {
public:
    int t[301];
    bool solve(string s,int idx,unordered_set<string>& dict,int n){
        if(idx==n){
            return true;
        }

        if(t[idx]!=-1) return t[idx];

        if(dict.find(s)!=dict.end()){
            return true;
        }
        for(int l=1;idx+l<=n;l++){
            string temp=s.substr(idx,l);
            if(dict.find(temp)!=dict.end() && solve(s,idx+l,dict,n)) return t[idx]=true;
        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s,0,dict,s.size());
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/word-break/)