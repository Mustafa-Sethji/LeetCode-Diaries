# Satisfiability of Equality Equations

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array of strings `equations` that represent relationships between variables where each string `equations[i]` is of length `4` and takes one of two different forms: `"xi==yi"` or `"xi!=yi"`.Here, `xi` and `yi` are lowercase letters (not necessarily different) that represent one-letter variable names.

Return `true`* if it is possible to assign integers to variable names so as to satisfy all the given equations, or *`false`* otherwise*.

 

**Example 1:**

```
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

```

**Example 2:**

```
Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

```

 

**Constraints:**

- 1 <= equations.length <= 500
- equations[i].length == 4
- equations[i][0] is a lowercase letter.
- equations[i][1] is either '=' or '!'.
- equations[i][2] is '='.
- equations[i][3] is a lowercase letter.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.2 MB (beats 27.78%)  
**Submitted:** 2026-09-18T06:59:35.254Z  

```cpp
class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent)return;

        if(rank[x_parent]>rank[y_parent])parent[y_parent]=x_parent;
        else if(rank[y_parent]>rank[x_parent])parent[x_parent]=y_parent;
        else{
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.assign(26,0);
        for(int i=0;i<26;i++)parent[i]=i;

        for(string &s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        for(string &s:equations){
            if(s[1]=='!'){
                if(find(s[0]-'a')==find(s[3]-'a'))return false;
            }
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/satisfiability-of-equality-equations/)