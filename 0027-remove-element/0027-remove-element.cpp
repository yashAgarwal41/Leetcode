class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int n = v.size(), ind = 0;
        for(int i=0; i<n; i++)
        {
            if(v[i]!=val)
            {
                v[ind] = v[i];
                ind++;
            }
        }
        return ind;
    }
};