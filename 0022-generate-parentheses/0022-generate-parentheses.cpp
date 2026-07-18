class Solution {
public:
    void generate(string s, int n, int a,int b, vector<string>&ans){
        if(s.size()==2*n) ans.push_back(s);
        if(a<n){
            generate(s+'(', n, a+1, b, ans);
        }
        if(b<a){
            generate(s+')', n, a, b+1, ans);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="(";
        generate(s, n,1,0,ans);
        return ans;
    }
};