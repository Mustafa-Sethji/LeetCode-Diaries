class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<0;i++){
            sum+=nums[i];
        }
    }
            if(mp.find(sum%k)!=mp.end())return true;
            else if(sum%k==0) return true;
            else mp[sum%k]=1;
        return false;
};
