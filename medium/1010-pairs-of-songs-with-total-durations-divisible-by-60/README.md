# Pairs of Songs With Total Durations Divisible by 60

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 
Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60


Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.


 
Constraints:


	1 <= time.length <= 6 * 104
	1 <= time[i] <= 500

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-09-13T11:49:41.173Z  

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>freq(60,0);
        int ans=0;
        for(int i=0;i<time.size();i++){
            int rem=time[i]%60;
        }
    }
        return ans;
            int need=(60-rem)%60;
            ans+=freq[need];
            freq[rem]++;
};

```

---

[View on LeetCode](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)