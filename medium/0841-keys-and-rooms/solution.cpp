class Solution {
public:
    int room;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        room=rooms.size();
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<room;i++){
            for(auto &it:rooms[i]){
                adj[i].push_back(it);
            }
        }
        queue<int>q;
        vector<int>vis(room,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto key:adj[node]){
                if(!vis[key]){
                    q.push(key);
                    vis[key]=1;
                }
            }
        }
        for(int x: vis)if(x==0)return false;    
        return true;
    }
};