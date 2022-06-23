class Solution {
public:
    bool help(int i, vector<int> &v, vector<int> &vis)
    {
        if(i<0 or i>=v.size())  return 0;
        if(v[i]==0) return 1;
        if(vis[i]==1)   return 0;
        vis[i]=1;
        bool left = help(i-v[i], v, vis);
        bool right = help(i+v[i], v, vis);
        return left or right;
    }
    bool canReach(vector<int>& v, int start) {
        vector<int> vis(v.size(), 0);
        return help(start, v, vis);
    }
};

