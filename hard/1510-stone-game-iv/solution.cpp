class Solution {
public:
    vector<int>dp;
    int solve(int i){
        if(i==0) return 0;
        if(i==1)return 1;

        if(dp[i]!=-1)return dp[i];

        int result=-1;

        for(int k=1;i-(k*k)>=0;k++){
            if (solve(i - k * k) == 0)
                return dp[i] = 1;
        }
        return dp[i]=0;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        if(solve(n)==1)return true;
        return false;
    }
};