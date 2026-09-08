class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int n=nums.size();
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;

            //check if its present in map

            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2) return true;
            }
            else mp[rem]=i;
        }
        return false;
    }
};