class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=maxi;
        }
        int maxi=INT_MIN;
            maxi=max(maxi,nums[i]);
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
        }
        int mini=INT_MAX;
            temp[i]-=mini;
        for(int i=0;i<n;i++){
            if(temp[i]<=k) return i;
        }
    }
        return -1;
};
