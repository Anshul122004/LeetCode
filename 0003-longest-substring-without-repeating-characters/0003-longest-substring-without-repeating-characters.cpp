class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int l=0;
        int n=s.size();
        int maxlen=0;
        for(int r=0;r<n;r++){
            if(mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};