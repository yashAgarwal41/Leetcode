class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size(), j = 0;
        for(int i=1; i<n; i++)
        {
            if(v[i-1] != v[i])
            {
                v[j] = v[i-1];
                j++;
            }
        }
        v[j] = v[n-1];
        j++;
        return j;
    }
};