class Solution {
public:
    unordered_map<int,int>mp;
    vector<int>arr;
    vector<int>dp;
    int n;
    int solve(int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int take=mp[arr[i]]*arr[i];
        if(i+1<n && arr[i]+1==arr[i+1]) take+=solve(i+2);
        else take+=solve(i+1);
        
        int skip=solve(i+1);

        return dp[i]=max(take,skip);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
                arr.push_back(nums[i]);
            }
                mp[nums[i]]++;
        }
        n=arr.size();
        dp.assign(n,-1);
        return solve(0);

    }
};