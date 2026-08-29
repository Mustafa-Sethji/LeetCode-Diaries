class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {

        //  for rook (a,b)
        if(a==e || b==f) return 1;

        //bishop(c,d)
        int i=c,j=d;
        while(i>0 && j>0){
            if(i==e && j==f) return 1;
            i--;
            j--;
        }
        i=c,j=d;
        while(i>0 && j<=8){
            if(i==e && j==f) return 1;
            i--;
            j++;
        }
        i=c,j=d;
        while(i<=8 && j>0){
            if(i==e && j==f) return 1;
            i++;
            j--;
        }
        i=c,j=d;
        while(i<=8 && j<=8){
            if(i==e && j==f) return 1;
            i++;
            j++;
        }
        return 2;
    }      
};