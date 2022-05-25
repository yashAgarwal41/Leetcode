class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> v(1,1);
        for(int i=1; i<=n; i++)
        {
            vector<int> temp;
            for(int j=0; j<=i; j++)
            {
                if(j==0 or j==i)    temp.push_back(1);
                else 
                {
                    temp.push_back(v[j-1] + v[j]);
                }
            }
            v = temp;
        }
        return v;
    }
};