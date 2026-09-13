# 4Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:


	0 <= a, b, c, d < n
	a, b, c, and d are distinct.
	nums[a] + nums[b] + nums[c] + nums[d] == target


You may return the answer in any order.

 
Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


 
Constraints:


	1 <= nums.length <= 200
	-109 <= nums[i] <= 109
	-109 <= target <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-09-13T12:06:06.522Z  

```cpp
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
       vector<vector<int>>ans;
       int n=nums.size();
       for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int k=j+1;
            }
        }
class Solution {
public:
                int l=n-1;
                while(k<l){
                    long long sum=
                }
                                1LL * nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum<target)k++;
                    else if(sum>target)l--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    }
    }
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                        while(k<l && nums[l]==nums[l+1])l--;
        return ans;
};

```

---

[View on LeetCode](https://leetcode.com/problems/4sum/)