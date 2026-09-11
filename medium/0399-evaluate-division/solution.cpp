        vector<vector<double>>adj(lab,vector<double>(lab,INT_MAX));
        for(int i=0;i<lab;i++)adj[i][i]=1;

        for(int i=0;i<equations.size();i++){
            adj[label_chk[equations[i][0]]][label_chk[equations[i][1]]]=values[i];
            adj[label_chk[equations[i][1]]][label_chk[equations[i][0]]]=1/values[i];
        }

        for(int via=0;via<lab;via++){
            for(int i=0;i<lab;i++){
                for(int j=0;j<lab;j++){
                    if(adj[i][via]!=INT_MAX && adj[via][j]!=INT_MAX && adj[i][j]==INT_MAX){
                        adj[i][j]=adj[i][via]*adj[via][j];
                    }
                }
            }
        }
        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            if(label_chk.find(queries[i][0])==label_chk.end() || label_chk.find(queries[i][1])==label_chk.end() )ans.push_back(-1);
            else if(adj[label_chk[queries[i][0]]][label_chk[queries[i][1]]]!=INT_MAX)ans.push_back(adj[label_chk[queries[i][0]]]
            [label_chk[queries[i][1]]]);
            else ans.push_back(-1);
        }

        return ans;
    }
};
