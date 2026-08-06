class Solution {
public:
    int product(int x){
        int n=x;
        if(n==0)return x;
        int ans=1;
        while(n!=0){
            int digit=n%10;
            ans*=digit;
            n=n/10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int i=n;
        while(i<=100){
            int prod=product(i);
            if(prod%t==0)return i;
            i++;
        }
        return -1;
    }
};