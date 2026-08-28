# Lexicographically Smallest Palindromic Permutation Greater Than Target

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given two strings s and target, each of length n, consisting of lowercase English letters.

Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such permutation exists, return an empty string.

 
Example 1:


Input: s = "baba", target = "abba"

Output: "baab"

Explanation:


	The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
	The lexicographically smallest permutation that is strictly greater than target is "baab".



Example 2:


Input: s = "baba", target = "bbaa"

Output: ""

Explanation:


	The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
	None of them is lexicographically strictly greater than target. Therefore, the answer is "".



Example 3:


Input: s = "abc", target = "abb"

Output: ""

Explanation:

s has no palindromic permutations. Therefore, the answer is "".


Example 4:


Input: s = "aac", target = "abb"

Output: "aca"

Explanation:


	The only palindromic permutation of s is "aca".
	"aca" is strictly greater than target. Therefore, the answer is "aca".



 
Constraints:


	1 <= n == s.length == target.length <= 300
	s and target consist of only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 63.08%)  
**Memory:** 12.2 MB (beats 67.69%)  
**Submitted:** 2026-08-28T13:21:07.639Z  

```cpp
class Solution {
public:
    char midChar='$';
    string result="";
    int halfLen=0;
    bool solve(string& curr,vector<int>& count, string& target,int i,bool greater){
        if(curr.size()==halfLen){
            string candidate=curr;
            string rightHalf=curr;
            reverse(rightHalf.begin(),rightHalf.end());
            if(midChar!='$'){
                candidate+=midChar;
            }
            candidate+=rightHalf;

            if(candidate>target){
                result=candidate;
                return true;
            }
            return false;
        }
        for(char ch='a';ch<='z';ch++){
            if(count[ch-'a']==0)continue;

            if(!greater && ch<target[i])continue;

            //Do
            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater=greater || ch>target[i];

            //explore
            if(solve(curr,count,target,i+1,isGreater)){ //early return
                return true;
            }

            //undo
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int>count(26,0);
        for(char &ch:s){
            count[ch-'a']++;
        }
        int oddCount=0; //odd frequency wale kitne charcter hai
        for(int c=0;c<26;c++){
            if(count[c]%2==1){
                oddCount++;
                midChar=c+'a';
            }
        }
        if(oddCount>1){
            return ""; //not possible to make a palindrome
        }

        //for left half of palindrome
        for(int c=0;c<26;c++){
            count[c]/=2;
        }  

        halfLen=n/2;

        string curr;
        solve(curr,count,target,0,false);

        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/)