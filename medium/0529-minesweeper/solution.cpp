        if(mines>0){
            board[r][c]='0'+mines;
            return;
        }
        for(int i=0;i<8;i++){
            int n_r=r+d_row[i];
            int n_c=r+d_col[i];
            if(n_r<n && n_r>=0 && n_c>=0 && n_c<m && vis[n_r][n_c]==0){
                dfs(n_r,n_c,board);
            }
        }
    }

        board[r][c]='B';
        }
            }
                mines++;
            if(n_r<n && n_r>=0 && n_c>=0 && n_c<m && board[n_r][n_c]=='M'){
            int n_c=r+d_col[i];
        return;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        cr=click[0];
        cc=click[1];
        n=board.size();
        m=board[0].size();
        if(board[cr][cc]=='M'){
            board[cr][cc]='X';
            return board;
        }
        vis.assign(n,vector<int>(m,0));
        dfs(cr,cc,board);
        return board;
    }
