class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            if(hash.find(nums[i])==hash.end()){ 
        }
        int ans=0;
        int j=0;
                hash[nums[i]]++;
            }
            else{
                if(hash[nums[i]]<k){
            }

                    hash[nums[i]]++;
                }
                else{
                    while(hash[nums[i]]==k){
                }
                        hash[nums[j]]--;
                    }
    }
                        j++;
            ans=max(ans,i-j+1);
        return ans;
};
