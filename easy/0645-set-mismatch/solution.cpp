class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        long long sum=n*(n+1)/2;
        long long sum_of_sq=n*(n+1)*(2*n+1)/6;
        long long sum_arr=0,sum_sq_arr=0;
        for(int i=0;i<n;i++){
            sum_arr+=nums[i];
            sum_sq_arr+=nums[i]*nums[i];
        }
        int x=sum-sum_arr; //no-dup
        int y=sum_of_sq-sum_sq_arr; //no^2-dup^2
        y=y/x;//no+dup
        return{(y-x)/2,(x+y)/2};
    }
};