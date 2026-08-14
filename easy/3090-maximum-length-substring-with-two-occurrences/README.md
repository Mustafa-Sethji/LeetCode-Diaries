# Maximum Length Substring With Two Occurrences

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 
Example 1:


Input: s = "bcbbbcba"

Output: 4

Explanation:
The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".

Example 2:


Input: s = "aaaa"

Output: 2

Explanation:
The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".

 
Constraints:


	2 <= s.length <= 100
	s consists only of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.7 MB (beats 44.69%)  
**Submitted:** 2026-08-14T08:03:29.262Z  

```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>map;
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(map.find(ch)!=map.end()){
                while(map[ch]==2){
                    map[s[j]]--;
                    j++;
                }
                map[ch]++;
                ans=max(ans,i-j+1);
            }
            else{
                map[ch]++;
                ans=max(i-j+1,ans);
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/)