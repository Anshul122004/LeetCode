class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0,r=0;
        int n=s.size();
        int maxlen=0;
        while(r<n){
            if(!mp.count(s[r])||mp[s[r]]<l){
                maxlen=max(maxlen,r-l+1);
                mp[s[r]]=r;
            }else{
                l=mp[s[r]]+1;
                mp[s[r]]=r;
            }
            r++;
        }
        return maxlen;
    }
};