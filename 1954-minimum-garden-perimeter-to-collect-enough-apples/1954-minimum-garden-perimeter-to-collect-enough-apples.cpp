class Solution {
public:
    //Refer https://www.youtube.com/watch?v=8zkULr3VDC4&ab_channel=CodeinDepth
    long long minimumPerimeter(long long neededApples) {
        long long n = 1;
        long long apples = 0;
        while(apples < neededApples)
        {
            apples += 12*n*n;
            n++;
        }
        return 8*(n-1);
    }
};