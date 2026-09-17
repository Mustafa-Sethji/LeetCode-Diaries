# Find Two Non-overlapping Sub-arrays Each With Target Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array of integers `arr` and an integer `target`.

You have to find **two non-overlapping sub-arrays** of `arr` each with a sum equal `target`. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is **minimum**.

Return *the minimum sum of the lengths* of the two required sub-arrays, or return `-1` if you cannot find such two sub-arrays.

 

**Example 1:**

```
Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.

```

**Example 2:**

```
Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.

```

**Example 3:**

```
Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.

```

 

**Constraints:**

- 1 <= arr.length <= 105
- 1 <= arr[i] <= 1000
- 1 <= target <= 108

## Solution

**Language:** C++  
**Runtime:** 159 ms (beats 40.21%)  
**Memory:** 149.4 MB (beats 15.21%)  
**Submitted:** 2026-09-17T11:15:22.770Z  

```cpp
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> nxt;

    int solve(int i, int k) {

        // We have found required subarrays
        if (k == 0)
            return 0;

        // Not enough elements
        if (i >= n)
            return 1e9;

        if (dp[i][k] != -1)
            return dp[i][k];

        // Don't take a subarray starting at i
        int ans = solve(i + 1, k);

        // Take the subarray starting at i
        if (nxt[i] != -1) {

            int j = nxt[i];

            int len = j - i + 1;

            int remaining = solve(j + 1, k - 1);

            if (remaining != 1e9) {
                ans = min(ans, len + remaining);
            }
        }

        return dp[i][k] = ans;
    }

    int minSumOfLengths(vector<int>& arr, int target) {

        n = arr.size();

        nxt.assign(n, -1);

        // --------------------------------
        // Step 1: Find target subarrays
        // --------------------------------

        int left = 0;
        long long sum = 0;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (left <= right && sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                nxt[left] = right;
            }
        }

        // --------------------------------
        // Step 2: Top-Down DP
        // --------------------------------

        dp.assign(n, vector<int>(3, -1));

        int ans = solve(0, 2);

        return ans == 1e9 ? -1 : ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)