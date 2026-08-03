class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int solve(int i,int j,vector<int>&piles){
        if(i==j)return dp[i][i]=piles[i];
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int first=piles[i]-solve(i+1,j,piles);
        int last=piles[j]-solve(i,j-1,piles);

        return dp[i][j]=max(first,last);
    }
    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,piles)>=0;
    }
};