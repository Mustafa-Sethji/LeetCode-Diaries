# Q1. Set Mismatch

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 
Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:
Input: nums = [1,1]
Output: [1,2]

 
Constraints:


	2 <= nums.length <= 104
	1 <= nums[i] <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 25.1 MB (beats 74.14%)  
**Submitted:** 2026-09-06T05:10:59.267Z  

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        long long sum=n*(n+1)/2;
        long long sum_of_sq=n*(n+1)*(2*n+1)/6;
        long long sum_arr=0,sum_sq_arr=0;
        for(int i=0;i<n;i++){
            sum_arr+=nums[i];
            sum_sq_arr+=nums[i]*nums[i];
        }
        int x=sum-sum_arr; //no-dup
        int y=sum_of_sq-sum_sq_arr; //no^2-dup^2
        y=y/x;//no+dup
        return{(y-x)/2,(x+y)/2};
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/set-mismatch/)