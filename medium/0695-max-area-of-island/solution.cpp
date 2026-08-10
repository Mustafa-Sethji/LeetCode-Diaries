        int maxi=max_area;
        while(!q.empty()){
            int row=q.front().first.
            first;
            int col=q.front().first.
            second;
            int curr_area=q.front().
            second;
            q.pop();
            for(int i=0;i<4;i++){
                int n_row=row+d_row[i];
                int n_col=col+d_col[i];
                if(n_row<n && 
                n_row>=0 && n_col<m && 
                n_col>=0 && !vis[n_row]
                [n_col] && grid[n_row]
                [n_col]==1){
                    q.push({{n_row,
                    n_col},curr_area+1});
                    maxi=max(maxi,
                    curr_area+1);
                    vis[n_row][n_col]=1;
                }
            }
        }
        return maxi;

    }
