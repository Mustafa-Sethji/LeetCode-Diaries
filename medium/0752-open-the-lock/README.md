# Open the Lock

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

 
Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".


Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".


Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.


 
Constraints:


	1 <= deadends.length <= 500
	deadends[i].length == 4
	target.length == 4
	target will not be in the list deadends.
	target and deadends[i] consist of digits only.

## Solution

**Language:** C++  
**Runtime:** 57 ms  
**Memory:** 12.7 MB  
**Submitted:** 2026-08-30T16:49:03.569Z  

```cpp
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<vector<string>>ans;
        bool found=false;
        while(!q.empty() && !found){
            int size=q.size();
            set<string>used;
            while(size--){
                vector<string> temp=q.front();
                string word=temp.back();
                q.pop();
                for(int i=0;i<word.size();i++){
                    char original=word[i];
                    for(char ch='a';ch<='z';ch++){
                        if(original==ch)continue;
                        word[i]=ch;

                        if(st.find(word)!=st.end()){
                            temp.push_back(word);

                            if(word==endWord){
                                ans.push_back(temp);
                                found=true;
                            }
                            else {q.push(temp);}
                            
                            used.insert(word);
                            temp.pop_back();
                        }
                    }
                    word[i]=original;
                }
            }
            for(string x:used) st.erase(x);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/open-the-lock/)