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