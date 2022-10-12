class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        for(int i=n-1; i>=2; i--)
        {
            if(v[i] < v[i-1] + v[i-2])  return v[i] + v[i-1] + v[i-2];
        }
        return 0;
    }
};