class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor==-1)    return INT_MAX;
        int sign = (dividend>=0 == divisor>=0) ? 1 : -1;
        long dvd = labs(dividend), dvs=labs(divisor);
        long ans=0;
        while(dvd>=dvs)
        {
            long temp = dvs, cnt = 1;
            while(temp<<1 <= dvd)
            {
                temp=temp<<1;
                cnt=cnt<<1;
            }
            ans+=cnt;
            dvd=dvd-temp;
        }
        
        return sign*ans;
    }
};