# Maximum Score of Non-overlapping Intervals

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.

Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.

 
Example 1:


Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]

Output: [2,3]

Explanation:

You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.


Example 2:


Input: intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]

Output: [1,3,5,6]

Explanation:

You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.


 
Constraints:


	1 <= intevals.length <= 5 * 104
	intervals[i].length == 3
	intervals[i] = [li, ri, weighti]
	1 <= li <= ri <= 109
	1 <= weighti <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-09-12T07:31:47.102Z  

```cpp
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<int> start(n);
        for (int i = 0; i < n; i++)
            start[i] = intervals[i][0];

        vector<array<long long, 5>> dp(n + 1);

        for (int i = n - 1; i >= 0; i--) {
            int j = lower_bound(start.begin(), start.end(), intervals[i][1] + 1) - start.begin();

            array<long long, 5> take = dp[j];
            take[0] += intervals[i][2];

            array<long long, 5> skip = dp[i + 1];

            if (take[0] > skip[0]) {
                dp[i] = take;
            } else if (take[0] < skip[0]) {
                dp[i] = skip;
            } else {
                dp[i] = skip;
            }
        }

        vector<pair<long long, vector<int>>> memo(n + 1);
        memo[n] = {0, {}};

        for (int i = n - 1; i >= 0; i--) {
            int j = lower_bound(start.begin(), start.end(), intervals[i][1] + 1) - start.begin();

            auto take = memo[j];
            take.first += intervals[i][2];
            take.second.push_back(i);

            auto skip = memo[i + 1];

            if (take.first > skip.first) {
                memo[i] = take;
            } else if (take.first < skip.first) {
                memo[i] = skip;
            } else {
                vector<int> a = take.second;
                vector<int> b = skip.second;

                for (int& x : a) x = intervals[x][3];
                for (int& x : b) x = intervals[x][3];

                sort(a.begin(), a.end());
                sort(b.begin(), b.end());

                memo[i] = (a < b ? take : skip);
            }
        }

        vector<int> ans;
        for (int idx : memo[0].second)
            ans.push_back(intervals[idx][3]);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/)