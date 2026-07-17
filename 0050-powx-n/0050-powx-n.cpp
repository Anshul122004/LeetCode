class Solution {
public:
    double power(double x, long n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2==1){
            return x*power(x,n-1);
        }
        return power(x*x,n/2);
    }
    double myPow(double x, int n) {
        if(n<0){
            long num=n;
            return 1.0/power(x, -1*num);
        }
        return power(x,n);
    }
};