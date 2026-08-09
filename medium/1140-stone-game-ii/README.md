# Stone Game II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 
Example 1:


Input: piles = [2,7,9,4,4]

Output: 10

Explanation:


	If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
	If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.


So we return 10 since it's larger.


Example 2:


Input: piles = [1,2,3,4,5,100]

Output: 104


 
Constraints:


	1 <= piles.length <= 100
	1 <= piles[i] <= 104

## Solution

**Language:** C++  
**Runtime:** 25 ms (beats 22.91%)  
**Memory:** 16.8 MB (beats 23.21%)  
**Submitted:** 2026-08-09T04:30:58.383Z  

```cpp
class Solution {
public:
    vector<vector<vector<int>>>dp;
    int n;
    int solve_for_alice(int person,int i,int M,vector<int>&piles){
        if(i>=n)return 0;
        if(dp[person][i][M]!=-1)return dp[person][i][M];
        int result;
        if(person==1)result=-1;
        else result=INT_MAX;
        int stones=0;
        for(int x=1;x<=2*M;x++){
            if(i+x-1<n){
                stones+=piles[i+x-1];
                if(person==1){
                    result=max(result,stones+solve_for_alice(0,i+x,max(x,M),piles));
                }
                else{
                    result=min(result,solve_for_alice(1,i+x,max(x,M),piles));
                }
            }
        }
        return dp[person][i][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.assign(2,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return solve_for_alice(1,0,1,piles);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/stone-game-ii/)