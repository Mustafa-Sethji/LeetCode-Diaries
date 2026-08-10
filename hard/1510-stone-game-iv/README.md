# Stone Game IV

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

 
Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.

Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).


Example 3:

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).


 
Constraints:


	1 <= n <= 105

## Solution

**Language:** C++  
**Runtime:** 43 ms (beats 57.44%)  
**Memory:** 16.8 MB (beats 39.10%)  
**Submitted:** 2026-08-10T01:39:54.428Z  

```cpp
class Solution {
public:
    vector<int>dp;
    int solve(int i){
        if(i==0) return 0;
        if(i==1)return 1;

        if(dp[i]!=-1)return dp[i];

        int result=-1;

        for(int k=1;i-(k*k)>=0;k++){
            if (solve(i - k * k) == 0)
                return dp[i] = 1;
        }
        return dp[i]=0;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        if(solve(n)==1)return true;
        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/stone-game-iv/)