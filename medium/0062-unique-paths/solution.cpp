class Solution {
public:
    int countpath(int i,int j,int row,int col,vector<vector<int>>&dp){
        if(i==row-1 && j==col-1) return 1;
        if(i>=row || j>=col) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j]=countpath(i,j+1,row,col,dp)+countpath(i+1,j,row,col,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return countpath(0,0,m,n,dp);
    
    }
};