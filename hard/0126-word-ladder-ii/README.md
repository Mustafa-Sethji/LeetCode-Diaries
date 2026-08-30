# Word Ladder II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:


	Every adjacent pair of words differs by a single letter.
	Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
	sk == endWord


Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 
Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"


Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


 
Constraints:


	1 <= beginWord.length <= 5
	endWord.length == beginWord.length
	1 <= wordList.length <= 500
	wordList[i].length == beginWord.length
	beginWord, endWord, and wordList[i] consist of lowercase English letters.
	beginWord != endWord
	All the words in wordList are unique.
	The sum of all shortest transformation sequences does not exceed 105.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.8 MB  
**Submitted:** 2026-08-30T15:44:20.540Z  

```cpp
class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endWord)return level;
            for(int i=0;i<word.size();i++){
                char orginal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i]=orginal;
            }
        }
        return 0;
    }
};












```

---

[View on LeetCode](https://leetcode.com/problems/word-ladder-ii/)