        }
                if(isWater[i][j]==1){
            }
                    vis[i][j]=1;
                }
                    dis[i][j]=0;
                    q.push({{i,j},0});

        vector<int>d_row={-1,1,0,0};
        vector<int>d_col={0,0,1,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int distance=q.front().second;
            for(int i=0;i<4;i++){
                int new_row=r+d_row[i];
                int new_col=c+d_col[i];
                if(new_row<n && new_row>=0 && new_col<m && new_col>=0 && !vis[new_row][new_col]){
                    dis[new_row][new_col]=distance+1;
                    vis[new_row][new_col]=1;
                    q.push({{new_row,new_col},distance+1});
                }              
            }
        }
        return dis;
    }
            q.pop();
};
