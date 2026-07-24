class Solution {
public:
    void comb(int sum, int ind, int k, vector<vector<int>> &ans,vector<int>&ds){
        if(sum==0&&ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(sum<=0||ds.size()>k){
            return;
        }
        for(int i=ind;i<=9;i++){
            if(i<=sum){
                ds.push_back(i);
                comb(sum-i, i+1,k,ans,ds);
                ds.pop_back();
            }else{
                break;
            }
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        comb(n,1,k, ans, ds);
        return ans;
    }
};