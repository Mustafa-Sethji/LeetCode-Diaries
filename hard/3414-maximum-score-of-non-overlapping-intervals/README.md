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
**Runtime:** 2289 ms (beats 19.56%)  
**Memory:** 421.4 MB (beats 5.43%)  
**Submitted:** 2026-09-12T07:32:37.889Z  

```cpp
class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    vector<vector<Node>> dp;
    vector<vector<int>> intervals;
    vector<int> start;
    int n;

    bool better(Node a, Node b) {
        if (a.score != b.score)
            return a.score > b.score;

        sort(a.ids.begin(), a.ids.end());
        sort(b.ids.begin(), b.ids.end());

        return a.ids < b.ids;
    }

    Node solve(int i, int cnt) {
        if (i == n || cnt == 4)
            return {0, {}};

        if (dp[i][cnt].score != -1)
            return dp[i][cnt];

        int j = lower_bound(
            start.begin(),
            start.end(),
            intervals[i][1] + 1
        ) - start.begin();

        Node take = solve(j, cnt + 1);
        take.score += intervals[i][2];
        take.ids.push_back(intervals[i][3]);

        Node skip = solve(i + 1, cnt);

        if (better(take, skip))
            return dp[i][cnt] = take;

        return dp[i][cnt] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& input) {
        n = input.size();
        intervals = input;

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        start.resize(n);

        for (int i = 0; i < n; i++)
            start[i] = intervals[i][0];

        dp.assign(n, vector<Node>(4, {-1, {}}));

        vector<int> ans = solve(0, 0).ids;

        sort(ans.begin(), ans.end());

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/)