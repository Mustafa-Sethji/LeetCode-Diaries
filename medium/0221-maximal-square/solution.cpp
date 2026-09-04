class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<char>>& matrix){
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.assign(n,vector<int>(m,-1));
        solve(0,0,matrix);
        if(i>=n || j>=m)return 0;
    }
        int right=solve(i,j+1,matrix);
        int below=solve(i+1,j+1,matrix);
        int left=solve(i+1,j,matrix);

        return dp[i][j]=(matrix[i][j]-'0')+min(right,min(below,left));

        // if(matrix[i][j] == '0')return dp[i][j] = 0;

        if(dp[i][j]!=-1)return dp[i][j];

    int n,m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
        }
                maxside=max(maxside,dp[i][j]);
            }
    }
        int maxside=INT_MIN;
        return maxside*maxside;
};
