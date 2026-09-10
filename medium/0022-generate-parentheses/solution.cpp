class Solution {
public:
    void generate(vector<string>&v,int &n,string s,int open,int close){
        if(s.size()==2*n){
            v.emplace_back(s);
            return;
        }
        if(open<n)generate(v,n,s+'(',open+1,close);
        if(close<open)generate(v,n,s+')',open,close+1);

        return;
    }
    vector<string> generateParenthesis(int n) {
        // vistr collect;
        // string str="";
        // generate(collect,n,str,0,0);
        // return collect;
        vector<string>collect;
        string str="";
        generate(collect,n,str,0,0);
        return collect;
    }
};