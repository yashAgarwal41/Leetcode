class Solution {
public:
    //TC-O(n), SC-O(2n)
    //Attach another array of size n to our vector assigning value 0..
    //now traverse from i=0; i<n. If we find 0<v[i]<=n, then update the index v[v[i]+n-1] = 1;
    //now traverse from i=n; i<2*n. If v[i] = 0, then return ans...
    int firstMissingPositive(vector<int>& v) {
        int n=v.size();
        for(int i=0; i<n; i++)
        {
            v.push_back(0);
        }
        for(int i=0; i<n; i++)
        {
            if(v[i]<=0) continue;
            if(v[i]<=n)
            {
                v[v[i] + n-1] = 1;
            }
        }
        for(int i=n; i<2*n; i++)
        {
            if(v[i]==0) return (i%n)+1;
        }
        return n+1;
    }
};