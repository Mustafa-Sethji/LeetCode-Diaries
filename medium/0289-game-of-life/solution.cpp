        vector<vector<int>>ans(n,vector<int>(m,-1));
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
        }
                int cnt_1=0;
            }
                int cnt_0=0;
                for(auto &it:directions){
                    int i_=i+it[0];
                }
                    int j_=j+it[1];
                    if(i_>=n || i_<0 || j_>=m || j_<0)continue;
                    if(board[i_][j_]==0)cnt_0++;
                    else cnt_1++;
                if(board[i][j]==0){
                    if(cnt_1==3)ans[i][j]=1;
                }
                else{
                    else ans[i][j]=board[i][j];
                    if(cnt_1<2)ans[i][j]=0;
                }
    }
                    else if(cnt_1==2 || cnt_1==3)ans[i][j]=1;
                    else if(cnt_1>3)ans[i][j]=0;
        board=ans;
        return ;
public:
    vector<vector<int>>directions={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
class Solution {
