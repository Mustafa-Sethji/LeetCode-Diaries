class Solution {
public:
    vector<vector<int>>dp;
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        
        
        dp.assign(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ans_length=n+m-dp[m][n];  //length of SuperSubSequence

        string ans="";
        int i=m,j=n;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(s1[i-1]);
                    i--;
                }
                else{
                    ans.push_back(s2[j-1]);
                    j--;
                }

            }
        }
        while(i > 0){
            ans.push_back(s1[i-1]);
            i--;
        }

        while(j > 0){
            ans.push_back(s2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};