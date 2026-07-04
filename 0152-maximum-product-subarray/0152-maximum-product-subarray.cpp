class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1, sufix=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefix==0) prefix=1;
            prefix*=nums[i];
            maxi=max(maxi,prefix);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(sufix==0) sufix=1;
            sufix*=nums[i];
            maxi=max(maxi,sufix);
        }
        return maxi;
    }
};