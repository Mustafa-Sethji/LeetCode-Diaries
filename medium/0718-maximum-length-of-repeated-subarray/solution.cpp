class Solution {
public:
    vector<vector<int>>dp;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        dp.assign(n+1,vector<int>(m+1,0));
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;
            }
        }
        for(int i=0;i<=n;i++){
            int mx=*max_element(dp[i].begin(),dp[i].end());
            maxi=max(maxi,mx);
        }
        return maxi;

    }
};