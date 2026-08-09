# Word Ladder

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:


	Every adjacent pair of words differs by a single letter.
	Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
	sk == endWord


Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 
Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.


Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


 
Constraints:


	1 <= beginWord.length <= 10
	endWord.length == beginWord.length
	1 <= wordList.length <= 5000
	wordList[i].length == beginWord.length
	beginWord, endWord, and wordList[i] consist of lowercase English letters.
	beginWord != endWord
	All the words in wordList are unique.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-08-09T14:00:48.603Z  

```cpp
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                for(char ch='a';ch<='z';ch++){
                char orginal=word[i];
            for(int i=0;i<word.size();i++){
            if(word==endWord)return level;
            string word=q.front().first;
            int level=q.front().second;
        while(!q.empty()){
        q.push({beginWord,1});
        st.erase(beginWord);
        set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     return cnt;
    // }
    //     }
    //     for(int i=0;i<a.size();i++){
    //         if(a[i]!=b[i])cnt++;
    //     int cnt=0;
            q.pop();
    
    // int diff(string &a,string &b){
public:
class Solution {

```

---

[View on LeetCode](https://leetcode.com/problems/word-ladder/)