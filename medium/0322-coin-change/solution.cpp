class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int solve(int i,int amt,vector<int>&coins){
        if(i==0){
            if(amt%coins[i]==0)return amt/coins[i];
            return INT_MAX;
        }

        if(dp[i][amt]!=-1)return dp[i][amt];
        int not_take=0+solve(i-1,amt,coins);
        int take=INT_MAX;
        if(coins[i]<=amt){
            int res = solve(i, amt - coins[i], coins);
            if (res != INT_MAX) take = 1 + res;
        }

        return dp[i][amt]=min(take,not_take);
    }

    int coinChange(vector<int>& coins, int amt) {
        if(amt<1) return 0;
        n=coins.size();

        dp.assign(n,vector<int>(amt+1,-1));

        int ans = solve(n - 1, amt, coins);
        return (ans == INT_MAX) ? -1 : ans;


        //Bott0m up
        vector<int>min_dp(amt+1,INT_MAX);
        min_dp[0]=0;
        for(int i=1;i<=amt;i++){
            for(int coin:coins){
                if(coin<=i && min_dp[i-coin]!=INT_MAX)
                    min_dp[i]=min(min_dp[i],1+min_dp[i-coin]);
            }
        }
        if(min_dp[amt]==INT_MAX)return -1;
        return min_dp[amt];
    }
};
// kutti sali