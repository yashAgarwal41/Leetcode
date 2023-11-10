class Solution {
public:
    int getWinner(vector<int>& v, int k) {
        int n = v.size(), cnt=0;
        for(int i=0; i<n-1; i++)
        {
            if(v[i] > v[i+1])
            {
                swap(v[i], v[i+1]);
                cnt++;
            }
            else cnt=1;
            if(cnt == k)   return v[i+1];
        }
        return *max_element(v.begin(), v.end());
    }
};