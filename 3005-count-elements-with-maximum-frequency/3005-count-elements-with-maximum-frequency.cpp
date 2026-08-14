class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int el:nums){
            mp[el]++;
        }
        int count=0;
        for(auto &p:mp){
           count = max(count, p.second);
        }
        int ans=0;
        for(auto &p:mp){
            if(mp[p.first]==count){
                ans+=p.second;
            }
        }
        return ans;
    }
};