class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>freq(60,0);
        int ans=0;
        for(int i=0;i<time.size();i++){
            int rem=time[i]%60;
            int need=(60-rem)%60;
            ans+=freq[need];
            freq[rem]++;
        }
        return ans;
    }
};