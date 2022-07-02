class Solution {
public:
    //Greedy..
    int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        int maxWidth = 0;
        int maxHeight = 0;
        hor.push_back(0);
        hor.push_back(h);
        ver.push_back(0);
        ver.push_back(w);
        int n = hor.size(), m = ver.size();
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        
        for(int i=1; i<n; i++)
        {
            maxHeight = max(maxHeight, hor[i]-hor[i-1]);
        }
        for(int i=1; i<m; i++)
        {
            maxWidth = max(maxWidth, ver[i]-ver[i-1]);
        }
        int ans = 1LL*maxHeight*maxWidth%mod;
        return ans;
    }
};