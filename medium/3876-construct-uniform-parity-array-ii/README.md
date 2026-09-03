# Construct Uniform Parity Array II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array nums1 of n distinct integers.

You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

For each index i, you must choose exactly one of the following (in any order):


	nums2[i] = nums1[i]​​​​​​​
	nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1


Return true if it is possible to construct such an array, otherwise return false.

 
Example 1:


Input: nums1 = [1,4,7]

Output: true

Explanation:​​​​​​​​​​​​​​


	Set nums2[0] = nums1[0] = 1.
	Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3.
	Set nums2[2] = nums1[2] = 7.
	nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.



Example 2:


Input: nums1 = [2,3]

Output: false

Explanation:

It is not possible to construct nums2 such that all elements have the same parity. Thus, the answer is false.


Example 3:


Input: nums1 = [4,6]

Output: true

Explanation:


	Set nums2[0] = nums1[0] = 4.
	Set nums2[1] = nums1[1] = 6.
	nums2 = [4, 6], and all elements are even. Thus, the answer is true.



 
Constraints:


	1 <= n == nums1.length <= 105
	1 <= nums1[i] <= 109
	nums1 consists of distinct integers.

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 65.18%)  
**Memory:** 165.9 MB (beats 62.83%)  
**Submitted:** 2026-09-03T11:17:41.498Z  

```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            }
        }

        // If an even number is smaller than the smallest odd,
        // we cannot make all elements have the same parity.
        for (int x : nums1) {
            if (x % 2 == 0 && minOdd != INT_MAX && x < minOdd) {
                return false;
            }
        }

        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/construct-uniform-parity-array-ii/)