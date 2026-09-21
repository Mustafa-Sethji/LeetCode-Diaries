class Solution {
public:
    int n;
    vector<long long>result;
    vector<long long>prevCount;
    vector<long long> resultArray(vector<int>& nums, int k) {
        n=nums.size();
        prevCount.assign(k,0);
        result.assign(k,0);
        for(int i=0;i<n;i++){

            //index i par end hone wale all subarrays
            vector<long long>currCount(k,0);
            int currElementRem=nums[i]%k;
            currCount[currElementRem]+=1;

            for(int oldRem=0;oldRem<k;oldRem++){
                int newRem= ((long long)oldRem*nums[i] %k)%k;

                currCount[newRem]+=prevCount[oldRem];
            }

            prevCount=std::move(currCount);

            for(int x=0;x<k;x++){
                result[x]+=prevCount[x];
            }
        }
        return result;
    }
};