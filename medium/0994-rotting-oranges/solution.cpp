        }
            }
        int minutes=0;
        if(fresh_orange==0)return 0;
        vector<int>d_row={-1,0,1,0};
        while(!q.empty()){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
        vector<int>d_col={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int new_row=r+d_row[i];
                } 
                    int new_col=c+d_col[i];
                    if(new_row<n && new_row>-1 && new_col<m && new_col>-1){
                        if(grid[new_row][new_col]==1){
                    }
                            fresh_orange--;
                        }
                            q.push({new_row,new_col});
                            grid[new_row][new_col]=2;
            minutes++;           
        }

            int qsize=q.size();
            while(qsize--){
            }
        if(fresh_orange==0)return minutes;
        return -1;
    }
};
