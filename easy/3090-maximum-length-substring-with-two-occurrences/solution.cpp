class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>map;
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(map.find(ch)!=map.end()){
                while(map[ch]==2){
                    map[s[j]]--;
                    j++;
                }
                map[ch]++;
                ans=max(ans,i-j+1);
            }
            else{
                map[ch]++;
                ans=max(i-j+1,ans);
            }
        }
        return ans;
    }
};
