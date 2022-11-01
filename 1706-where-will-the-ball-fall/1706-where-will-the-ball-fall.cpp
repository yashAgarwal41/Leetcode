class Solution {
public:
    vector<int> findBall(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<int> res(m, 0);
        
        for(int col=0; col<m; col++)
        {
            int i=0, j=col;
            bool chk = true;
            int ans=-1;
            while(i<n)
            {
                if(v[i][j] == -1)
                {
                    if(j==0 or v[i][j-1]==1)
                    {
                        res[col] = -1;
                        break;
                    }
                    else
                    {
                        j--;    
                    }
                }
                else
                {
                    if(j==m-1 or v[i][j+1] == - 1)
                    {
                        res[col] = -1;
                        break;
                    }
                    else j++;
                }
                i++;
                if(j<0 or j>=m) 
                {
                    res[col] = -1;
                    chk = false;
                    break;
                }
            }
            
            if(res[col]!=-1)  res[col] = j; 
        }
        return res;
    }
};