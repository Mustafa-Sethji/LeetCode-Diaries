class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        // step-1 find the j th pointer from right side
        int j=n-1;
        while(j>0 && arr[j]>=arr[j-1]){
            j--;
        }

        int i=0;
        int result=n;

        //step-2 start finding correct i and j and find deleted elemnt  j-i-1
        while(){

            //arr[j]>=arr[i]
            while(j<n && arr[i]>arr[j]){
                j++;
            }

            we have found correct j element such that arr[i]<=arr[j]


        }
    }
};