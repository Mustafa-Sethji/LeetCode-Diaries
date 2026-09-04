# House Robber

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.


Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


 
Constraints:


	1 <= nums.length <= 100
	0 <= nums[i] <= 400

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.6 MB (beats 46.86%)  
**Submitted:** 2026-09-04T07:25:45.992Z  

```cpp
class Solution {
public:
    vector<int>dp;
    int n;
    int solve(int i,vector<int>&nums){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];

        int steal=nums[i]+solve(i+2,nums);
        int skip=solve(i+1,nums);

        return dp[i]=max(steal,skip);

    }
    int rob(vector<int>& nums) {
        // // memset(dp,-1,sizeof(dp));
        // // solve(nums,0);
        // int n=nums.size();
        // vector<int>t(n+1,-1);
        // t[0]=0;
        // t[1]=nums[0];
        // for(int i=2;i<=n;i++){
        //     int steal=nums[i-1]+t[i-2];
        //     int skip=t[i-1];
        //     t[i]=max(steal,skip);
        // }
        // return t[n];

        n=nums.size();
        dp.assign(n,-1);
        return solve(0,nums);


    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/house-robber/)