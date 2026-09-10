# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:
Input: n = 1
Output: ["()"]

 
Constraints:


	1 <= n <= 8

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 67.74%)  
**Memory:** 15.5 MB (beats 64.61%)  
**Submitted:** 2026-09-10T04:30:26.942Z  

```cpp
class Solution {
public:
    void generate(vector<string>&v,int &n,string s,int open,int close){
        if(s.size()==2*n){
            v.emplace_back(s);
            return;
        }
        if(open<n)generate(v,n,s+'(',open+1,close);
        if(close<open)generate(v,n,s+')',open,close+1);

        return;
    }
    vector<string> generateParenthesis(int n) {
        // vistr collect;
        // string str="";
        // generate(collect,n,str,0,0);
        // return collect;
        vector<string>collect;
        string str="";
        generate(collect,n,str,0,0);
        return collect;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)