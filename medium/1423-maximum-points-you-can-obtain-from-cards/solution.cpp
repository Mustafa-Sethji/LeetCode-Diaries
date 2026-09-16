class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ans=0;
        for(int i=0;i<k;i++)ans+=cardPoints[i];

        int maxi=ans;
        int j=n-1;
        for(int i=k-1;i>=0;i--){
            ans=ans-cardPoints[i];
            ans=ans+cardPoints[j--];

            maxi=max(maxi,ans);
        }
        return maxi;
    }
};