# Wiggle Subsequence

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A **wiggle sequence** is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

- For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
- In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.

A **subsequence** is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array `nums`, return *the length of the longest **wiggle subsequence** of *`nums`.

 

**Example 1:**

```
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).

```

**Example 2:**

```
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

```

**Example 3:**

```
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2

```

 

**Constraints:**

- 1 <= nums.length <= 1000
- 0 <= nums[i] <= 1000

 

**Follow up:** Could you solve this in `O(n)` time?

## Solution

**Language:** C++  
**Runtime:** 10 ms (beats 16.38%)  
**Memory:** 17.5 MB (beats 15.03%)  
**Submitted:** 2026-09-17T15:00:03.233Z  

```cpp
class Solution {
public:
    vector<vector<int>>dp;
    int n;
    vector<int>arr;
    int solve(int i,int prev){
        if(i>=n)return 0;

        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int not_take=0+solve(i+1,prev);

        int take=0;

        if(prev == -1) {
            if(arr[i] != 0)
                take = 1 + solve(i + 1, i);
        }
        else if(arr[prev]>0 && arr[i]<0)take=1+solve(i+1,i);
        else if(arr[prev]<0 && arr[i]>0)take=1+solve(i+1,i);

        return dp[i][prev+1]=max(take,not_take);

    }
    int wiggleMaxLength(vector<int>& nums) {
        arr.clear();

        if(nums.size()<=1)return nums.size();

        for(int i=0;i<nums.size()-1;i++){
            arr.push_back(nums[i+1]-nums[i]);
        }

        n=arr.size();
        // if(n<=1)return n+1; 

        dp.assign(n+1,vector<int>(n+1,-1));

        return solve(0,-1)+1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/wiggle-subsequence/)