class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.empty())return s;
        sort(pairs.begin(),pairs.end());
        int i=0;
        int n=pairs.size();
        int n_ch=s.size();
        vector<char>ans(n_ch);
        while(i<n){
            int j=i;
            set<int>st;
            while( j<n && ( st.empty() || st.find(pairs[j][0])!=st.end() || st.find(pairs[j][1])!=st.end() ) ){
                st.insert(pairs[j][0]);
                st.insert(pairs[j][1]);
                j++;
            }
            vector<int>indices;
            vector<char>character;
            for(int x : st){
                indices.push_back(x);
                character.push_back(s[x]);
            }

            sort(character.begin(),character.end());

            for(int k=0;k<indices.size();k++){
                ans[indices[k]]=character[k];
            }
            i=j;
        }
        string a="";
        for(char ch:ans)a+=ch;
        return a;

    }
};