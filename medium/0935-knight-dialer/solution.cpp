        dial[0]={4,6};
        dial[1]={6,8};
        dial[2]={7,9};
        dial[3]={4,8};
        dial[4]={0,3,9};
        
        dial[6]={0,1,7};
        dial[7]={2,6};
        dial[8]={1,3};
        dial[9]={2,4};
        int ans=0;
            ans+=solve(i,n-1,dial,vis,dp);
    }
    int knightDialer(int n) {
        unordered_map<int,vector<int>>dial;
        for(int i=0;i<10;i++){
            vector<int>vis(10,0);
        vector<vector<int>>dp(n,vector<int>(10,-1));
            if(!vis[x]){
        }
                paths+=solve(x,length-1,dial,vis,dp);
            }
        return dp[length][num]=paths;
        int paths=0;
        for(int x:dial[num]){
        if(length==0)return 1;
        if(dp[length][num]!=-1)return dp[num][length];
        vis[num]=1;
    int N;
    int solve(int num,int length,unordered_map<int,vector<int>>&dial,vector<int>&vis,
        }
    vector<vector<int>>&dp){
