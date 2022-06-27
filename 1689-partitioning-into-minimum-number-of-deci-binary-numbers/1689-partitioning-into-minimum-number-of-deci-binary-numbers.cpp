class Solution {
public:
    int minPartitions(string s) {
        char maxi = '1';
        for(auto c:s)
        {
            maxi = max(maxi, c);
        }
        return maxi-'0';
    }
};