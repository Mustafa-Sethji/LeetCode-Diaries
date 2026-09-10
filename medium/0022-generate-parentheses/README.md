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
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-09-10T04:30:22.271Z  

```cpp
class Solution {
public:
    typedef vector <string> vistr;
    void generate(vistr &vi,int n,string str,int open,int close){
        if(str.size()==2*n){
            vi.emplace_back(str);
            return;
        }
        if(open<n)generate(vi,n,str+'(',open+1,close);
        if(close<open)generate(vi,n,str+')',open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vistr collect;
        string str="";
        generate(collect,n,str,0,0);
        return collect;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)