class Solution {
public:
    //Sliding Window, TC-O(n)
    int longestNiceSubarray(vector<int>& v) {
        int n = v.size();
        int OR = 0;
        //OR is the or of all elements of our window, so we don't have to check for all the pairs of window to satisy the condition of (a and b == 0)..
        //whenever we don't get 0, then move the left pointer of the window and xor the OR with that element, so to disclude it from the or's of our window..
        int i=0, j=0, maxi=1;
        while(i<n and j<n)
        {
            while((OR & v[j]) != 0)
            {
                OR ^= v[i];
                i++;
            }
            maxi = max(maxi, j-i+1);
            OR |= v[j];
            j++;
        }
        return maxi;
    }
};