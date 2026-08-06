class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int initial=image[sr][sc];
        vector<int>d_row={1,-1,0,0};
        vector<int>d_col={0,0,1,-1};
        image[sr][sc]=color;
        while(!q.empty()){
            int q_size=q.size();
            while(q_size--){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int row=it.first+d_row[i];
                    int col=it.second+d_col[i];
                    if(row<n && row>=0 && col<m && col>=0){
                        if(image[row][col]!=color && image[row][col]==initial){
                            image[row][col]=color;
                            q.push({row,col});
                        }
                    }
                }
            }
        }
        return image;
    }
};