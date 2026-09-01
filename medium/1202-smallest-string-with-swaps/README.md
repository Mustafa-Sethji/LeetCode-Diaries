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
**Memory:** 8.2 MB  
**Submitted:** 2026-09-01T06:11:02.992Z  

```cpp
        int i=0;
        int n=pairs.size();
        while(i<n){
            int j=i;
            set<int>st;
            while( j<n && ( st.empty() || st.find(pairs[j][0])!=st.end() || st.find(pairs[j][1])!=st.end() ) ){
                st.insert(pairs[j][0]);
                st.insert(pairs[j][1]);
                j++;
            }
            vector<int>indices;
            for(int x : st){
        }
        vector<char>ans(n_ch);
        int n_ch=s.size();
            for(int k=0;k<indices.size();k++){
                ans[indices[k]]=character[k];
            }
            vector<char>character;
                indices.push_back(x);
            }
                character.push_back(s[x]);
            sort(character.begin(),character.end());


        string a="";
        for(char ch:ans)a+=ch;
            i=j;
        return a;

    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/smallest-string-with-swaps/)