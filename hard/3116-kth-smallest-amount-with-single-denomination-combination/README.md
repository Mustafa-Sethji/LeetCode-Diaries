# Kth Smallest Amount With Single Denomination Combination

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array coins representing coins of different denominations and an integer k.

You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.

Return the kth smallest amount that can be made using these coins.

 
Example 1:


Input: coins = [3,6,9], k = 3

Output:  9

Explanation: The given coins can make the following amounts:
Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
All of the coins combined produce: 3, 6, 9, 12, 15, etc.


Example 2:


Input: coins = [5,2], k = 7

Output: 12 

Explanation: The given coins can make the following amounts:
Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.
All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.


 
Constraints:


	1 <= coins.length <= 15
	1 <= coins[i] <= 25
	1 <= k <= 2 * 109
	coins contains pairwise distinct integers.

## Solution

**Language:** C++  
**Runtime:** 206 ms (beats 16.28%)  
**Memory:** 20.7 MB (beats 46.51%)  
**Submitted:** 2026-08-21T03:25:52.111Z  

```cpp
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Count valid distinct amounts <= x
        auto count = [&](long long x) -> long long {
            long long cnt = 0;

            // Iterate over every non-empty subset
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                bool overflow = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcd(l, (long long)coins[i]);

                        // Prevent LCM from becoming unnecessarily large
                        if (l / g > x / coins[i]) {
                            overflow = true;
                            break;
                        }

                        l = (l / g) * coins[i];
                    }
                }

                if (overflow || l > x) continue;

                // Inclusion-Exclusion
                if (__builtin_popcount(mask) % 2 == 1)
                    cnt += x / l;
                else
                    cnt -= x / l;
            }

            return cnt;
        };

        long long low = 1;
        long long high = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/)