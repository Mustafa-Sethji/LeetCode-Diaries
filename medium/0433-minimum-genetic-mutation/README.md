# Minimum Genetic Mutation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.


	For example, "AACCGGTT" --> "AACCGGTA" is one mutation.


There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 
Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1


Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2


 
Constraints:


	0 <= bank.length <= 10
	startGene.length == endGene.length == bank[i].length == 8
	startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-08-30T16:39:22.225Z  

```cpp
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        if(st.find(startGene)!=st.end())st.erase(startGene);
        while(!q.empty()){
        }
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endGene)return level;
            for(int i=0;i<word.size();i++){
                char original=word[i];
            }
                word[i]=original;
                for(char ch='A';ch<='Z';ch++){
                    word[i]=ch;
                }
                    if(ch==original)continue;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                    }
    }
                        st.erase(word);
        return -1;
};

```

---

[View on LeetCode](https://leetcode.com/problems/minimum-genetic-mutation/)