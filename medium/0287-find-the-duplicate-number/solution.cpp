class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];;
        }while(slow!=fast);
        int p=0;
        while(p!=slow){
            p=nums[p];
            slow=nums[slow];
        }
        return p;
    }
};