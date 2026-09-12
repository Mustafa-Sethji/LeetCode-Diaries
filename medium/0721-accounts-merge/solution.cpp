class Solution {
public:vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x); 
        int y_parent=find(y); 
        if(x_parent==y_parent) return;

        if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
        else if(rank[y_parent]>rank[x_parent]) parent[x_parent]=y_parent;
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>mpMail_node;
        parent.assign(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        rank.assign(n,0);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpMail_node.find(mail)==mpMail_node.end()){
                    mpMail_node[mail]=i;
                }
                else{
                    Union(i,mpMail_node[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto &it:mpMail_node){
            string mail=it.first;
            int node=find(it.second);
            mergedMail[node].push_back(mail);
        }
        

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0)continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};