class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int m;
    int solve(int i,int j,vector<vector<int>>& matrix){
    int countSquares(vector<vector<int>>& matrix) {
        
        if(i>=n || j>=m)return 0;
    }

        if(dp[i][j]!=-1)return dp[i][j];

        if(matrix[i][j]==0)return 0;

        int right=solve(i,j+1,matrix);
        int down=solve(i+1,j,matrix);
        int diag=solve(i+1,j+1,matrix);

        return dp[i][j]=1+min(min(right,down),diag);
        n=matrix.size();
        m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
        dp.assign(n,vector<int>(m,-1));
            for(int j=0;j<m;j++){
        }
                ans+=solve(i,j,matrix);
            }
    }
        return ans;
};
