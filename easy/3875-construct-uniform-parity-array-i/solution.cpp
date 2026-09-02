class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cnt_odd=0,cnt_even=0;

        for(int x:nums1){
            if((x&1)==1)cnt_odd++;
            else cnt_even++;
        }
        int n=nums1.size();
        if(n==cnt_odd || n==cnt_even)return true;
        return true;


    }
};