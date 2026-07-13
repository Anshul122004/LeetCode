class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, cnt=0, r=0;
        int n=nums.size();
        int maxlen=0;
        while(r<n){
            if(nums[r]==0&&cnt<=k){
                cnt++;
            }
            while(cnt>k){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
            maxlen=max(r-l+1, maxlen);
            r++;
        }
        return maxlen;   
    }
};