class Solution {
public:
    typedef vector <string> vistr;
    void generate(vistr &vi,int n,string str,int open,int close){
        if(str.size()==2*n){
            vi.emplace_back(str);
            return;
        }
        if(open<n)generate(vi,n,str+'(',open+1,close);
        if(close<open)generate(vi,n,str+')',open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vistr collect;
        string str="";
        generate(collect,n,str,0,0);
        return collect;
    }
};