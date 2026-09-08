    int knightDialer(int n) {
        unordered_map<int,vector<int>>dial;
        dial[0]={4,6};
        dial[1]={6,8};
        dial[2]={7,9};
        dial[3]={4,8};
        dial[4]={0,3,9};
        
        dial[6]={0,1,7};
        dial[7]={2,6};
        dial[8]={1,3};
        }
        return dp[length][num]=paths;
    }
        int ans=0;
        dial[9]={2,4};
            paths+=solve(x,length-1,dial,dp);
        int paths=0;
        for(int x:dial[num]){
        vector<vector<int>>dp(n,vector<int>(10,-1));
        for(int i=0;i<10;i++){
            ans = (ans + solve(i, n - 1, dial, dp)) % MOD;
        }
        return ans;
            paths %= MOD;

    }
};
        if(dp[length][num]!=-1)return dp[length][num];
        if(length==0)return 1;

