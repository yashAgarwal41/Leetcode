class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)    return false;
        if(floor(log2(n)/2.0) == ceil(log2(n))/2.0)
            return true;
        return false;
    }
};