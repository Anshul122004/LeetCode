class Solution {
public:
    int kadaneMax(vector<int> &nums, int n){
        int curSum=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            curSum=max(nums[i], curSum+nums[i]);
            ans=max(ans, curSum);
        }
        return ans;
    }
    int kadaneMin(vector<int> &nums, int n){
        int curSum=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            curSum=min(nums[i], curSum+nums[i]);
            ans=min(ans, curSum);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int minSum=kadaneMin(nums,n);
        int maxSum=kadaneMax(nums,n);
        int circSum=sum-minSum;
        if(circSum>0) return max(circSum,maxSum);
        else return maxSum;
    }
};