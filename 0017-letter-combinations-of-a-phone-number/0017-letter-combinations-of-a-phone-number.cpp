class Solution {
public:
    void combination(int ind, string digits, vector<string>&ans, string s, vector<string>&map){
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        }
        int number=digits[ind]-'0';
        string value=map[number];
        for(int i=0;i<value.size();i++){
            s.push_back(value[i]);
            combination(ind+1, digits, ans, s,map);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> ans;
        string s;
        vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        combination(0,digits,ans, s, map);
        return ans;
    }
};