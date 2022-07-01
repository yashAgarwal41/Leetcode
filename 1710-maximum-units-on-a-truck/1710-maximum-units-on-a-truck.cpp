class Solution {
public:
    static bool compare(vector<int> v1, vector<int> v2)
    {
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& v, int truckSize) {
        int n = v.size();
        sort(v.begin(), v.end(), compare);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int freq = min(truckSize, v[i][0]);
            ans += freq*v[i][1];
            truckSize -= freq;
            if(truckSize==0)    break;
        }
        return ans;
    }
};