class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int n=v[0].size(), ans=0;
        for(int c=0; c<n; c++)
        {
            int mini=v[0][c]-'a';
            for(int r=1; r<v.size(); r++)
            {
                int pos = v[r][c]-'a';
                if(pos<mini)    
                {
                    ans++;
                    break;
                }
                else mini=pos;
            }
        }
        return ans;
    }
};