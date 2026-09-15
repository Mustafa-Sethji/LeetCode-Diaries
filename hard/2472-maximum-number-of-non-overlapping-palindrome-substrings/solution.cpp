class Solution {
public:
    int n, k;
    vector<vector<bool>> pal;
    vector<int> dp;

    int solve(int i, string &s) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = solve(i + 1, s);

        for (int j = i + k - 1; j < n; j++) {
            if (pal[i][j]) {
                ans = max(ans, 1 + solve(j + 1, s));
            }
        }

        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {
        n = s.size();
        this->k = k;

        pal.assign(n, vector<bool>(n, false));
        dp.assign(n, -1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        return solve(0, s);
    }
};
