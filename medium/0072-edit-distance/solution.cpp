class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s1,string &s2,int i,int j){
        if(i<0)return j+1;
        if(j<0)return i+1;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,i-1,j-1);

        return dp[i][j]=1+min(solve(s1,s2,i-1,j),//delete
                            min(solve(s1,s2,i-1,j-1),//replace
                                solve(s1,s2,i,j-1)//insert
                                )
                            );
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.assign(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1);
    }
};