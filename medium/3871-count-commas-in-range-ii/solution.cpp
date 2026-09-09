class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        long long ttlcommas=0,helper=1000;
        while(n>=helper){
            ttlcommas+=n-helper+1;
            if(helper>1e15)break;
            helper*=1000;
        }
        return ttlcommas;
    }
};