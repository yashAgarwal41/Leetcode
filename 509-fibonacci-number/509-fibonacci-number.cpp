class Solution {
public:
    int fib(int n) {
        if(n==0)    return 0;
        if(n==1 or n==2)    return 1;
        int a=1, b=1;
        for(int i=3; i<=n; i++)
        {
            int c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};