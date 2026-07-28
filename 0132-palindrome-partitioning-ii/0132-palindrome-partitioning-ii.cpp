class Solution {
public:
    bool ispalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int minCnt=INT_MAX;
            for(int j=i;j<n;j++){
                if(ispalindrome(s, i, j)){
                    int cost=1+dp[j+1];
                    minCnt=min(minCnt, cost);
                }
            }
            dp[i]=minCnt;
        }
        return dp[0]-1;
    }
};