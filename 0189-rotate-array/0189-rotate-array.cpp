class Solution {
public:
    //tC_O(n), SC-O(1)
    void reverse(int l, int r, vector<int> &v)
    {
        for(int x=0,i=l; i<=(r+l)/2; i++, x++)
            swap(v[i], v[r-x]);
    }
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        k=k%n;
        reverse(0, n-k-1, v);
        reverse(n-k, n-1, v);
        reverse(0, n-1, v);
    }
};