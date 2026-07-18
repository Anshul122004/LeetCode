class Solution {
public:
    void Generate(string s, int n, vector<string> &ans){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        Generate(s+'1',n,ans);
        if(s.empty()||s.back()!='0'){
            Generate(s+'0',n,ans);
        }

    }
    vector<string> validStrings(int n) {
        string s="";
        vector<string> ans;
        Generate(s, n, ans);
        return ans;
    }
};