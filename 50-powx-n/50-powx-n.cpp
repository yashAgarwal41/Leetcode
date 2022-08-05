class Solution {
public:
    //Fast Exponentiation..Bitwise..TC-O(logn)..
    double multiply(double x, int n)
    {
        double p = x, ans=1;
        while(n>0)
        {
            if(n&1) ans *= p;
            p *= p;
            n = n>>1;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(n>=0)    return multiply(x, n);
        return 1/multiply(x, abs(n));
    }
};