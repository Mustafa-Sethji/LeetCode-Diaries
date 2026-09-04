class Solution {
public:
    vector<int>dp;
    int n;
    int solve(int i,vector<int>&nums){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];

        int steal=nums[i]+solve(i+2,nums);
        int skip=solve(i+1,nums);

        return dp[i]=max(steal,skip);

    }
    int rob(vector<int>& nums) {
        // // memset(dp,-1,sizeof(dp));
        // // solve(nums,0);
        // int n=nums.size();
        // vector<int>t(n+1,-1);
        // t[0]=0;
        // t[1]=nums[0];
        // for(int i=2;i<=n;i++){
        //     int steal=nums[i-1]+t[i-2];
        //     int skip=t[i-1];
        //     t[i]=max(steal,skip);
        // }
        // return t[n];

        n=nums.size();
        dp.assign(n,-1);
        return solve(0,nums);


    }
};