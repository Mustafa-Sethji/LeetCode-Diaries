class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>hash;
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(hash.find(nums[i])==hash.end()){ 
                hash[nums[i]]++;
            }
            else{
                if(hash[nums[i]]<k){
                    hash[nums[i]]++;
                }
                else{
                    while(hash[nums[i]]==k){
                        hash[nums[j]]--;
                        j++;
                    }
                    hash[nums[i]]++;
                }
            }
            ans=max(ans,i-j+1);

        }
        return ans;
    }
};