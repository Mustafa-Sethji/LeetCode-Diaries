# Longest Increasing Subsequence

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array nums, return the length of the longest strictly increasing subsequence.

 
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4


Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


 
Constraints:


	1 <= nums.length <= 2500
	-104 <= nums[i] <= 104


 
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

## Solution

**Language:** C++  
**Runtime:** 546 ms (beats 20.88%)  
**Memory:** 296.6 MB (beats 13.78%)  
**Submitted:** 2026-09-08T10:10:40.874Z  

```cpp
class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int solve(int i,int prev,vector<int> &nums){
        if(i>=n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int not_take=0+solve(i+1,prev,nums);

        int take=INT_MIN;
        if(prev==-1 || nums[i]>nums[prev]) take=1+solve(i+1,i,nums);

        return dp[i][prev+1]=max(take,not_take);

    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,-1,nums);


        // vector<int>tabulation_dp(n,1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j])
        //             tabulation_dp[i]=max(tabulation_dp[i],tabulation_dp[j]+1);
        //     }
        // }
        // return *max_element(tabulation_dp.begin(),tabulation_dp.end());


        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     int it=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
        //     if(it==ans.size())ans.emplace_back(nums[i]);
        //     else ans[it]=nums[i];
        // }
        // return ans.size();
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-increasing-subsequence/)