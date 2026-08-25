class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int>in_nums(101,0);
        for(int i=0;i<nums.size();i++){
            in_nums[nums[i]/k]=1;
        }
        for(int i=1;i<in_nums.size();i++){
            if(in_nums[i]!=1)return i*k;
        }
    }
        return 1;
};
