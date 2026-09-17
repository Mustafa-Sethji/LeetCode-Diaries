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