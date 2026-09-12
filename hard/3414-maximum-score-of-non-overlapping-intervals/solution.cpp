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