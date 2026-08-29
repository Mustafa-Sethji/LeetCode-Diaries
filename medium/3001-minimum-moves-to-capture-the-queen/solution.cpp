class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {

        //  for rook (a,b)
        if(a==e || b==f ) {
            if(a==c){
                if(!(a<c<e || e<c<a))return 1;
            }
            else if(b=d){
                if(!(b<d<f || f<d<b))return 1;
            }
            else return 1;
        }

        //bishop(c,d)
        int i=c,j=d;
        while(i>0 && j>0){
            if(i==a && j==b) break;
            if(i==e && j==f) return 1;
            i--;
            j--;
        }
        i=c,j=d;
        while(i>0 && j<=8){
            if(i==a && j==b) break;
            if(i==e && j==f) return 1;
            i--;
            j++;
        }
        i=c,j=d;
        while(i<=8 && j>0){
            if(i==a && j==b) break;
            if(i==e && j==f) return 1;
            i++;
            j--;
        }
        i=c,j=d;
        while(i<=8 && j<=8){
            if(i==a && j==b) break;
            if(i==e && j==f) return 1;
            i++;
            j++;
        }
        return 2;
    }      
};