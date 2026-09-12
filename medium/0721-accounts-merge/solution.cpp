                    Union(i,mpMail_node[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for(auto &it:mpMail_node){
            string mail=it.first;
            int node=find(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0)continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());

        

            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &it:mergedMail[i]){
                temp.push_back(it);
                else{
                }
                    mpMail_node[mail]=i;
                if(mpMail_node.find(mail)==mpMail_node.end()){
                string mail=accounts[i][j];
            for(int j=1;j<accounts[i].size();j++){
        for(int i=0;i<n;i++){
        rank.assign(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        parent.assign(n,0);
        unordered_map<string,int>mpMail_node;
