        int i=0;
        int n=pairs.size();
        while(i<n){
            int j=i;
            set<int>st;
            while( j<n && ( st.empty() || st.find(pairs[j][0])!=st.end() || st.find(pairs[j][1])!=st.end() ) ){
                st.insert(pairs[j][0]);
                st.insert(pairs[j][1]);
                j++;
            }
            vector<int>indices;
            for(int x : st){
        }
        vector<char>ans(n_ch);
        int n_ch=s.size();
            for(int k=0;k<indices.size();k++){
                ans[indices[k]]=character[k];
            }
            vector<char>character;
                indices.push_back(x);
            }
                character.push_back(s[x]);
            sort(character.begin(),character.end());


        string a="";
        for(char ch:ans)a+=ch;
            i=j;
        return a;

    }
};
