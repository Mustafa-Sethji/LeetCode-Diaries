class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n=img1.size();
        int maxCount=0;
        for(int row_offset=-n+1;row_offset<=n-1;row_offset++){
            for(int col_offset=-n+1;col_offset<=n-1;col_offset++){
                maxCount=max(maxCount,counting(img1,img2,row_offset,col_offset));
            }
        }
        return maxCount;
    int counting(vector<vector<int>>& img1, vector<vector<int>>& img2,int &row_offset,int &col_offset){
        for(int i=0;i<n;i++){
    }
        int cnt=0;
        return cnt;
            for(int j=0;j<n;j++){
        }
                int i_b=i+row_offset;
            }
    }
                int j_b=j+col_offset;
                if(i_b<0 || i_b>=n || j_b<0 || j_b>=n) continue;
                if(img1[i][j]==1 && img2[i_b][i_b]==1)cnt++;
    int n;
};
