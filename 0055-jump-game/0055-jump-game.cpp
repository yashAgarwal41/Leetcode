class Solution {
public:
    bool canJump(vector<int>& v) {
        int n =v.size();
        int maxi=v[0];
        if(maxi==0 && n>1) return false;
        for(int i=1; i<n; i++)
        {
            maxi--;
            maxi=max(maxi, v[i]);
            if(maxi==0 && i<n-1) return false;
        }
        return true;
    }
};