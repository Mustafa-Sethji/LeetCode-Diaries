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
**Runtime:** 140 ms  
**Memory:** 69.4 MB  
**Submitted:** 2026-09-01T07:09:39.521Z  

```cpp
class Solution {
public:
    int n;
    int m;
    vector<int>vis;
    void dfs(unordered_map<int,vector<int>> &graph,int node){
        vis[node]=m;
        for(int &x:graph[node]){
            if(!vis[x])dfs(graph,x);
        }
        return;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n=s.size();
        unordered_map<int,vector<int>>graph;
        vis.assign(n,0);
        for(auto &v:pairs){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        m=1;
        vector<char>ans(n); 

        for(int i=0;i<n;i++)ans[i]=s[i];

        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(graph,i);
            else continue;
            vector<int>idx;
            for(int k=0;k<n;k++){
                if(vis[k]==m){idx.push_back(k);}
            }
            vector<char>character;
            for(int x:idx)character.push_back(s[x]);
            sort(idx.begin(),idx.end());
            sort(character.begin(),character.end());
            for(int k=0;k<idx.size();k++){
                ans[idx[k]]=character[k];
            }
            m++;
        }

        string a=""; 
        for(char ch:ans)a+=ch; 
        return a;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/smallest-string-with-swaps/)