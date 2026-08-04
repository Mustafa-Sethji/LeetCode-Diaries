class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    string s1;
    string s2;
    int solve(int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i]==s2[j])return solve(i-1,j)+solve(i-1,j-1);
        return solve(i-1,j);
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        dp.assign(m,vector<int>(n,-1));
        s1=s;
        s2=t;
        return solve(m-1,n-1);
    }
};