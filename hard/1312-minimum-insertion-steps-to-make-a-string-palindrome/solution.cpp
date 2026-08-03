class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,string &s){
        if(i>=j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s);

        int inc_i=1+solve(i+1,j,s);
        int dec_j=1+solve(i,j-1,s);

        return dp[i][j]=min(inc_i,dec_j);
    }
    int minInsertions(string s) {
        int n=s.size();
        dp.assign(n, vector<int>(n,-1));
        int maxi=0;
        return solve(0,s.size()-1,s);
        // for(int i=0;i<s.size();i++){
        //     for(int j=0;j<s.size();j++){
        //         maxi=max(maxi,dp[i][j]);
        //     }
        // }
    }
};