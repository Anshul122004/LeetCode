class Solution {
public:
    void comb(string s, vector<string>&ans, int n){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        comb(s+'1',ans,n);
        if(s.empty()||s.back()!='0'){
            comb(s+'0',ans, n);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        comb("", ans, n);
        return ans;
    }
};