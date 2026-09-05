class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
    
        vector<int>mx(n,0);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[n-i-1]);
            mx[i]+=maxi;
            mx[n-i-1]-=mini;
        }
        for(int i=0;i<n;i++){
            if(mx[i]<=k)return i;
        }
        return -1;
    }
};