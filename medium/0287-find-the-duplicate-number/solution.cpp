class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        return nums[p];
        int fast=0;
        do{
            slow=nums[nums[slow]];
        }while(slow!=fast);
            fast=nums[nums[fast]];
            fast=nums[nums[fast]];
        int p=0;
        do{
        }while(p!=slow);
    }
            p=nums[nums[p]];
            slow=nums[nums[slow]];
};
