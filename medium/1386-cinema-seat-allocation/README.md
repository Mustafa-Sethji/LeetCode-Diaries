# Cinema Seat Allocation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:


	seats 2, 3, 4, 5
	seats 4, 5, 6, 7
	seats 6, 7, 8, 9


A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be assigned.

 
Example 1:



Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.


Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2


Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4


 
Constraints:


	1 <= n <= 109
	1 <= reservedSeats.length <= min(10 * n, 104)
	reservedSeats[i] == [rowi, seati]
	1 <= rowi <= n
	1 <= seati <= 10
	All reservedSeats[i] are distinct.

## Solution

**Language:** C++  
**Runtime:** 72 ms (beats 36.82%)  
**Memory:** 74.8 MB (beats 35.81%)  
**Submitted:** 2026-08-19T06:04:55.214Z  

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        map<int, set<int>> reserved;

        // Store reserved seats row-wise
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 to 9 matter
            if (col >= 2 && col <= 9) {
                reserved[row].insert(col);
            }
        }

        // Every completely empty row can accommodate 2 groups
        long long ans = 2LL * n;

        // Process only rows having relevant reservations
        for (auto &[row, seats] : reserved) {

            // Remove the default contribution of this row
            ans -= 2;

            bool left = true;   // seats 2,3,4,5
            bool middle = true; // seats 4,5,6,7
            bool right = true;  // seats 6,7,8,9

            // Check left block
            for (int i = 2; i <= 5; i++) {
                if (seats.count(i)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for (int i = 4; i <= 7; i++) {
                if (seats.count(i)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for (int i = 6; i <= 9; i++) {
                if (seats.count(i)) {
                    right = false;
                    break;
                }
            }

            int groups = 0;

            if (left && right) {
                groups = 2;
            }
            else if (left || middle || right) {
                groups = 1;
            }

            ans += groups;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/cinema-seat-allocation/)