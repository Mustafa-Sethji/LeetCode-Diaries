# Minimum Moves to Clean the Classroom

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:


	'S': Starting position of the student
	'L': Litter that must be collected (once collected, the cell becomes empty)
	'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
	'X': Obstacle the student cannot pass through
	'.': Empty space


You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.

Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.

Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.

 
Example 1:


Input: classroom = ["S.", "XL"], energy = 2

Output: 2

Explanation:


	The student starts at cell (0, 0) with 2 units of energy.
	Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
	A valid sequence of moves to collect all litter is as follows:
	
		Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
		Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
	
	
	The student collects all the litter using 2 moves. Thus, the output is 2.



Example 2:


Input: classroom = ["LS", "RL"], energy = 4

Output: 3

Explanation:


	The student starts at cell (0, 1) with 4 units of energy.
	A valid sequence of moves to collect all litter is as follows:
	
		Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining.
		Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4.
		Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
	
	
	The student collects all the litter using 3 moves. Thus, the output is 3.



Example 3:


Input: classroom = ["L.S", "RXL"], energy = 3

Output: -1

Explanation:

No valid path collects all 'L'.


 
Constraints:


	1 <= m == classroom.length <= 20
	1 <= n == classroom[i].length <= 20
	classroom[i][j] is one of 'S', 'L', 'R', 'X', or '.'
	1 <= energy <= 50
	There is exactly one 'S' in the grid.
	There are at most 10 'L' cells in the grid.

## Solution

**Language:** C++  
**Runtime:** 219 ms (beats 79.59%)  
**Memory:** 143.6 MB (beats 75.51%)  
**Submitted:** 2026-09-01T01:37:42.173Z  

```cpp
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int sr, sc;
        int litterCount = 0;

        // Assign an index to every litter cell
        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        // maxEnergy[r][c][mask] = maximum energy with which
        // we have reached (r,c) after collecting 'mask'
        vector<vector<vector<int>>> maxEnergy(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << litterCount, -1)
            )
        );

        // {row, col, energy, mask}
        queue<array<int, 4>> q;

        q.push({sr, sc, energy, 0});
        maxEnergy[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // One move consumes one energy
                    int ne = e - 1;

                    if (ne < 0)
                        continue;

                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Recharge at R
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // If we've already reached this state
                    // with equal or greater energy, skip it.
                    if (maxEnergy[nr][nc][nmask] >= ne)
                        continue;

                    maxEnergy[nr][nc][nmask] = ne;

                    q.push({nr, nc, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/)