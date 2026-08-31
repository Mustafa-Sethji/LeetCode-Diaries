class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>v;

        vector<int>ans(n);
        for(int i=0;i<nums.size();i++) v.push_back({nums[i],i});

        sort(v.begin(),v.end());

        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n && abs(v[j+1].first-v[j].first)<=limit)j++;

            vector<int>indices;

            for(int k=i;k<=j;k++){
                indices.push_back(v[k].second);
            }

            sort(indices.begin(),indices.end());

            for(int k=0;k<indices.size();k++){
                ans[indices[k]]=v[i+k].first;
            }
            i=j+1;
        }
        return ans;
    }
};