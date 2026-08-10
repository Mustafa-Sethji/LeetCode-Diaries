    vector<int>d_row={-1,-1,-1,1,1,1,0,0};
    vector<int>d_col={-1,1,0,-1,1,0,1,-1};
    void dfs(int r,int c,vector<vector<char>>& board){
        vis[r][c]=1;
        int mines = 0;
        for(int i=0;i<8;i++){
            int n_r=r+d_row[i];
            int n_c=r+d_col[i];
            if(n_r<n && n_r>=0 && n_c>=0 && n_c<m && board[n_r][n_c]=='M'){
                mines++;
            }
        }
        if(mines>0){

            board[r][c]='0'+mines;
            return;
        }
        board[r][c]='B';
        for(int i=0;i<8;i++){
                dfs(n_r,n_c,board);
            }
        }
        return;
    }
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
    int cr,cc;
    int n,m;
    vector<vector<int>>vis;
            int n_r=r+d_row[i];
            int n_c=r+d_col[i];
            if(n_r<n && n_r>=0 && n_c>=0 && n_c<m && vis[n_r][n_c]==0 && board[n_r][n_c]=='E'){
        return board;
    }
};
