class Solution {
public:
    vector<vector<int>> generate(int n){
        vector<vector<int>> res(n);
        res[0] = {1};
        for(int i=1; i<n; i++)
        {
            vector<int> temp;
            for(int j=0; j<=i; j++)
            {
                if(j==0 or j==i)    temp.push_back(1);
                else temp.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            res[i]=temp;
        }
        return res;
    }
};