class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int solve(int i,int prev,vector<int> &nums){
        if(i>=n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int not_take=0+solve(i+1,prev,nums);

        int take=INT_MIN;
        if(prev==-1 || nums[i]>nums[prev]) take=1+solve(i+1,i,nums);

        return dp[i][prev+1]=max(take,not_take);

    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,-1,nums);


        // vector<int>tabulation_dp(n,1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j])
        //             tabulation_dp[i]=max(tabulation_dp[i],tabulation_dp[j]+1);
        //     }
        // }
        // return *max_element(tabulation_dp.begin(),tabulation_dp.end());


        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     int it=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
        //     if(it==ans.size())ans.emplace_back(nums[i]);
        //     else ans[it]=nums[i];
        // }
        // return ans.size();
    }
};