class Solution {
public:
    int n;
    int m;
    vector<int>vis;
    void dfs(unordered_map<int,vector<int>> &graph,int node){
        vis[node]=m;
        for(int &x:graph[node]){
            if(!vis[x])dfs(graph,x);
        }
        return;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n=s.size();
        unordered_map<int,vector<int>>graph;
        vis.assign(n,0);
        for(auto &v:pairs){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        m=1;
        vector<char>ans(n); 

        for(int i=0;i<n;i++)ans[i]=s[i];

        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(graph,i);
            else continue;
            vector<int>idx;
            for(int k=0;k<n;k++){
                if(vis[k]==m){idx.push_back(k);}
            }
            vector<char>character;
            for(int x:idx)character.push_back(s[x]);
            sort(idx.begin(),idx.end());
            sort(character.begin(),character.end());
            for(int k=0;k<idx.size();k++){
                ans[idx[k]]=character[k];
            }
            m++;
        }

        string a=""; 
        for(char ch:ans)a+=ch; 
        return a;

    }
};