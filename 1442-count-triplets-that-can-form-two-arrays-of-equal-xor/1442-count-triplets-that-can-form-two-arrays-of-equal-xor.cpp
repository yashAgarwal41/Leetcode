class Solution {
public:
    //Brute Force, TC_O(n^3)..
    int countTriplets(vector<int>& v) {
        int n = v.size(), ans=0;
        int ax=0, bx=0;
        for(int i=0; i<n; i++)
        {
            ax=0;
            for(int j=i; j<n; j++)
            {
                ax ^= v[j];
                bx=0;
                for(int k=j+1; k<n; k++)
                {
                    bx ^= v[k];
                    if(bx==ax)  ans++;
                }
            }
        }
        return ans;
    }
};