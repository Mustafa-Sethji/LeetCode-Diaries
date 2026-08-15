# Longest Subsequence With Non-Zero Bitwise XOR

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

 
Example 1:


Input: nums = [1,2,3]

Output: 2

Explanation:

One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.


Example 2:


Input: nums = [2,3,4]

Output: 3

Explanation:

The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.


 
Constraints:


	1 <= nums.length <= 105
	0 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 43.09%)  
**Memory:** 171.4 MB (beats 22.70%)  
**Submitted:** 2026-08-15T03:03:57.876Z  

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        bool hasNonZero=false;
        for(int x:nums){
            xr^=x;
            if(x!=0) hasNonZero=true;
        }
        if(!hasNonZero)return 0;

        if(xr!=0)return n;

        return n-1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/)