class Solution {
public:
    void helper(vector<int> nums,int ind, vector<vector<int>> &ans, vector<int> &res){
        if(ind>=nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[ind]);
        helper(nums, ind+1, ans, res);
        res.pop_back();
        helper(nums,ind+1,ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        helper(nums, 0, ans, list);
        return ans;
    }
};