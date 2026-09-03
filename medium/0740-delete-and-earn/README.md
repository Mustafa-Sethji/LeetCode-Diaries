# Delete and Earn

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:


	Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.


Return the maximum number of points you can earn by applying the above operation some number of times.

 
Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.


Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.

 
Constraints:


	1 <= nums.length <= 2 * 104
	1 <= nums[i] <= 104

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 23.17%)  
**Memory:** 17.6 MB (beats 25.96%)  
**Submitted:** 2026-09-03T17:24:40.308Z  

```cpp
class Solution {
public:
    unordered_map<int,int>mp;
    vector<int>arr;
    vector<int>dp;
    int n;
    int solve(int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int take=mp[arr[i]]*arr[i];
        if(i+1<n && arr[i]+1==arr[i+1]) take+=solve(i+2);
        else take+=solve(i+1);
        
        int skip=solve(i+1);

        return dp[i]=max(take,skip);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
                arr.push_back(nums[i]);
            }
                mp[nums[i]]++;
        }
        n=arr.size();
        dp.assign(n,-1);
        return solve(0);

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/delete-and-earn/)