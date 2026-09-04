# Coin Change

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1


Example 2:

Input: coins = [2], amount = 3
Output: -1


Example 3:

Input: coins = [1], amount = 0
Output: 0


 
Constraints:


	1 <= coins.length <= 12
	1 <= coins[i] <= 231 - 1
	0 <= amount <= 104

## Solution

**Language:** C++  
**Runtime:** 47 ms (beats 35.60%)  
**Memory:** 49.3 MB (beats 33.85%)  
**Submitted:** 2026-09-04T06:35:29.601Z  

```cpp
class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int solve(int i,int amt,vector<int>&coins){
        if(i==0){
            if(amt%coins[i]==0)return amt/coins[i];
            return INT_MAX;
        }

        if(dp[i][amt]!=-1)return dp[i][amt];
        int not_take=0+solve(i-1,amt,coins);
        int take=INT_MAX;
        if(coins[i]<=amt){
            int res = solve(i, amt - coins[i], coins);
            if (res != INT_MAX) take = 1 + res;
        }

        return dp[i][amt]=min(take,not_take);
    }

    int coinChange(vector<int>& coins, int amt) {
        if(amt<1) return 0;
        n=coins.size();

        dp.assign(n,vector<int>(amt+1,-1));

        int ans = solve(n - 1, amt, coins);
        return (ans == INT_MAX) ? -1 : ans;


        //Bott0m up
        vector<int>min_dp(amt+1,INT_MAX);
        min_dp[0]=0;
        for(int i=1;i<=amt;i++){
            for(int coin:coins){
                if(coin<=i && min_dp[i-coin]!=INT_MAX)
                    min_dp[i]=min(min_dp[i],1+min_dp[i-coin]);
            }
        }
        if(min_dp[amt]==INT_MAX)return -1;
        return min_dp[amt];
    }
};
// kutti sali
```

---

[View on LeetCode](https://leetcode.com/problems/coin-change/)