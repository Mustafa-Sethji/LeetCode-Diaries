# Smallest String With Swaps

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 
Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"


Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"


 
Constraints:


	1 <= s.length <= 10^5
	0 <= pairs.length <= 10^5
	0 <= pairs[i][0], pairs[i][1] < s.length
	s only contains lower case English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-09-01T07:03:17.692Z  

```cpp
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.empty())return s;
        int n=pairs.size();

        for(int i=0;i<n;i++){
            if(pairs[i][0]>pairs[i][1]){
                int temp=pairs[i][1];
                pairs[i][1]=pairs[i][0];
                pairs[i][0]=temp;
            }
        }

        sort(pairs.begin(),pairs.end());
        int i=0;
        int n_ch=s.size();
        vector<char>ans(n_ch);
        for(int i=0;i<n_ch;i++)ans[i]=s[i];
        while(i<n){
            int j=i;
            set<int>st;
            while( j<n && ( st.empty() || st.find(pairs[j][0])!=st.end() || st.find(pairs[j][1])!=st.end() ) ){
                st.insert(pairs[j][0]);
                st.insert(pairs[j][1]);
                j++;
            }
            vector<int>indices;
            vector<char>character;
            for(int x : st){
                indices.push_back(x);
                character.push_back(s[x]);
            }

            sort(character.begin(),character.end());

            for(int k=0;k<indices.size();k++){
                ans[indices[k]]=character[k];
            }
            i=j;
        }
        string a="";
        for(char ch:ans)a+=ch;
        return a;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/smallest-string-with-swaps/)