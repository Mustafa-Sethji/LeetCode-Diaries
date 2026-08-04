            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(s1[i-1]);
            }
                j--;
                    i--;
                }
                else{
                    ans.push_back(s2[j-1]);
                    j--;
                }

            }
                i--;
                ans.push_back(s1[i-1]);
            if(s1[i-1]==s2[j-1]){
        int i=m,j=n;
        while(i>0 && j>0){
        string ans="";

        }
        int ans_length=n+m-dp[m][n];  //length of SuperSubSequence
            }
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            for(int j=1;j<=n;j++){
        dp.assign(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
        
        int n=s2.size();
        
        int m=s1.size();
