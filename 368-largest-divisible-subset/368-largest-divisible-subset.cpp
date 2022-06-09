class Solution {
public:
    //printing LIS question...
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n=v.size();
        sort(v.begin(), v.end());
        vector<int> lis(n, 1);
        vector<int> hash(n);
        int maxSize = 0, ind=0;
        for(int i=1; i<n; i++)
        {
            hash[i] = i;
            for(int j=0; j<i; j++)
            {
                if(v[i]%v[j] != 0)  continue;
                if(lis[j]+1 > lis[i])
                {
                    lis[i] = lis[j] + 1;
                    hash[i] = j;
                    
                    if(maxSize < lis[i])
                    {
                        maxSize = lis[i];
                        ind = i;
                    }
                }
            }
        }
        
        int i= ind;
        vector<int> res;
        while(hash[i]!=i)
        {
            res.push_back(v[i]);
            i = hash[i];
        }
        res.push_back(v[i]);
        reverse(res.begin(), res.end());
        return res;
    }
};