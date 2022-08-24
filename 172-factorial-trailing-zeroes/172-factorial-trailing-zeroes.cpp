class Solution {
public:
    //TC-O(n/5)..
    //ans = no of 10 from (1 to n) ==> no of (2*5) from (1 to n)..
    //no of 2 from (1 to n) will always be greater than no of 5 from (1 to n).. so just count no of 5..
    //count no of 5s from 1 to n..
    int trailingZeroes(int n) {
        if(n==0)    return 0;
        int cnt5=0;
        for(int i=5; i<=n; i+=5)
        {
            int j=i;
            while(j>0 and j%5==0)
            {
                cnt5++;
                j=j/5;
            }
        }
        
        return cnt5;
    }
};