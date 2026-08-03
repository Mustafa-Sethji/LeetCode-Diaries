class Solution {
public:
    vector<int>dp;
    int n;
    vector<int>prefix;
    int solve(int i){
        if(i == n-1) return prefix[n-1];

        if(dp[i]!=INT_MIN)return dp[i];

        int take=prefix[i]-solve(i+1);
        int skip=solve(i+1);

        return dp[i]=max(take,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        dp.assign(n,INT_MIN);
        prefix.assign(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
            prefix[i]=sum;
        }
        return solve(1);
    }
};