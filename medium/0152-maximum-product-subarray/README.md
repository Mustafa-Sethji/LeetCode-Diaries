# Maximum Product Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

 
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.


Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


 
Constraints:


	1 <= nums.length <= 2 * 104
	-10 <= nums[i] <= 10
	The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 17.7 MB (beats 60.34%)  
**Submitted:** 2026-09-04T06:37:44.352Z  

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,suffix=1,maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            maxi=max(maxi,max(prefix,suffix));
        }
        return maxi;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-product-subarray/)