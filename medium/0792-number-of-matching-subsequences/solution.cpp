class Solution {
public:
    unordered_map<char,vector<int>>hash;
    bool solve(string &s,string &sub){
        int prev=-1;
        for(int i=0;i<sub.size();i++){
            if(hash.find(sub[i])!=hash.end()){
                auto it=upper_bound(hash[sub[i]].begin(),hash[sub[i]].end(),prev);

                if(it==hash[sub[i]].end()) return false;

                prev=*it;
            }
            else return false;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=words.size();
        int count=0;

        for(int i=0;i<s.size();i++){
            hash[s[i]].push_back(i);
        }

        for(int i=0;i<n;i++){
            if(solve(s,words[i])){
                count++;
                cout<<words[i]<<"\n";
            }
        }
        return count;
    }
};