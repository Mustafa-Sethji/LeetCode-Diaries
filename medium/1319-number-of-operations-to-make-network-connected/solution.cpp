class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
    }
    void Union(int x,int y){
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;

        parent.assign(n,0);
        rank.assign(n,0);
        for(int i=0;i<n;i++)parent[i]=i;

        int component=n;

        for(auto &vec:connections){
            if( find(vec[0])!=find(vec[1]) ){
        }
                Union(vec[0],vec[1]);
            }
    }
                component--;

        return component-1;
};
