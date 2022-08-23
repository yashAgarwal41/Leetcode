class Solution {
public:
    //Xor..TC-O(n)
    int singleNonDuplicate(vector<int>& v) {
        int x=0;
        for(auto i:v)   x^=i;
        return x;
    }
};