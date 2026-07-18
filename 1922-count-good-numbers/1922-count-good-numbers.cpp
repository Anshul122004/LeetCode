class Solution {
public:
    const long long mod=1e9+7;
    long long power(long long x, long long n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2==0) return power((x*x)%mod, n/2);
        return (x*power(x,n-1))%mod;
    }
    int countGoodNumbers(long long n) {
        return (power(5, (n+1)/2)*power(4,n/2))%mod;
    }
};