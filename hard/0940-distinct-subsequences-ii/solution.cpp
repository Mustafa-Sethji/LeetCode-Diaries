class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> dp;

    long long solve(int i, string &s, vector<int> &prev) {
        if (i < 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        long long ans = (2LL * solve(i - 1, s, prev)) % MOD;

        if (prev[i] != -1) {
            ans -= solve(prev[i] - 1, s, prev);
            ans = (ans + MOD) % MOD;
        }

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> prev(n, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            prev[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }

        dp.assign(n, -1);

        return (solve(n - 1, s, prev) - 1 + MOD) % MOD;
    }
};