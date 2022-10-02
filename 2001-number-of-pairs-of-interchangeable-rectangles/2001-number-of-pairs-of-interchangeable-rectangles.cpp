class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        long long ans=0;
        unordered_map<double, int> map;
        for(auto &v:rectangles)
        {
            double ratio = (1.0*v[0])/v[1];
            ans += map[ratio];
            map[ratio]++;
        }
        return ans;
    }
};