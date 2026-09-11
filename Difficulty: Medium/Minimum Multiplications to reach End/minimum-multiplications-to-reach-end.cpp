#define mod 1000
class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        vector<int>vis(mod,-1);
        q.push({start,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it.first==end) return it.second;
            for(int x:arr){
                int num=(it.first*x)%mod;
                if(vis[num]==-1){
                    vis[num]=1;
                    q.push({num,it.second+1});
                }
            }
        }
        return -1;
    }
};