class Solution {
public:

    vector<int>del_row={0,0,1,-1};
    vector<int>del_col={-1,1,0,0};

    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        //vector<vector<int>>vis(n,vector<int>(n,0));

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                    //vis[i][j]=1;
                }
            }
        }

        if(q.empty() || q.size()==n*n)return -1;

        while(!q.empty()){
            int k=q.size();
            while(k--){

                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int r_=row+del_row[i];
                    int c_=col+del_col[i];
                    if(r_<n && r_>=0 && c_<n && c_>=0 && dist[r_][c_]>dist[row][col]+1){
                        dist[r_][c_]=dist[row][col]+1;
                        q.push({r_,c_});
                    }
                }

            }
        }


        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,*max_element(dist[i].begin(),dist[i].end()));
        } 
        return maxi;
    }
};