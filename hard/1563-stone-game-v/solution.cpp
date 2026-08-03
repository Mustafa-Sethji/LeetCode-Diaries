    int sum = 0;
    for (int i=s;i<=e;i++)sum+=v[i];

    int L = 0;
    int ans = 0;
    for (int i = s; i <= e; i++) {
        L += v[i];
        int R = sum - L;

        if (L > R)
            ans = max(ans, R + solve(i + 1, e, v));

        if (L <R)
            ans = max(ans, L + solve(s, i, v));

        if (L == R)
            ans = max(ans,
                      L + max(solve(i + 1, e, v),
                              solve(s, i, v)));
    }

        return dp[s][e];


    if (dp[s][e] != -1)
    return dp[s][e] = ans;
        return 0;
    if (s >= e)
}
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
    int solve(int s, int e, vector<int> &v) {
