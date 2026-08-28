        for(int i=0;i<s.size();i++){
            sort(hash[s[i]].begin(),hash[s[i]].end());
        }
        int count=0;
        int n=words.size();
    int numMatchingSubseq(string s, vector<string>& words) {
    }
            hash[s[i]].push_back(i);
        }
        for(int i=0;i<s.size();i++){



        }
        return true;
            else return false;
                for(int x:hash[sub[i]]){
            }
                    if(x>prev){
                }
                        prev=x;
                    }
                        break;
            if(hash.find(sub[i])!=hash.end()){
        int prev=-1;
        for(int i=0;i<sub.size();i++){
    bool solve(string &s,string &sub){
    unordered_map<char,vector<int>>hash;
public:
                bool found=false;
                        found=true;
                if(!found) return false;
