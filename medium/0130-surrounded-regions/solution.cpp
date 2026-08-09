    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
            }
                    if(!vis[i][j] && board[i][j]=='O'){
                }
                        dfs(i,j,board);
                    }
    }
        return ;
        }
        for(int i=1;i<n-1;i++){
        }
            if(n_c<m && n_c>=0 && n_r>=0 && n_r<n && board[n_r][n_c]=='O')dfs(n_r,n_c,board);
            int n_c=c+d_col[i];
            int n_r=r+d_row[i];
        for(int i=0;i<4;i++){
        vis[r][c]=1;
    void dfs(int r,int c,vector<vector<char>>& board){
    int n,m;
    vector<vector<int>>vis;
    vector<int>d_col={0,0,1,-1};
    vector<int>d_row={-1,1,0,0};
class Solution {
public:
