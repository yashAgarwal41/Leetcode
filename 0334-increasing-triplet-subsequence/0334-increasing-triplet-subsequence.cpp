//TC-O(n), SC-O(1)..
class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int n=v.size();
        int a=INT_MAX, b=INT_MAX;
        //a-1st element of the satisfying triplet..(always smaler than b)
        //b-2nd element of the satisfying triplet..(always greater than a)
        for(int i=0; i<n; i++)
        {
            if(v[i]<=a)  a=v[i];
            else if(v[i]<=b) b=v[i];
            else return true;   //if a and b both are smaller than v[i], then we got our ans
        }
        return false;
        
    }
};