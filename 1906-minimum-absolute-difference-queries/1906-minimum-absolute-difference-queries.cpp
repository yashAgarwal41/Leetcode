class Solution {
public:
    //Prefix Number, TC-O(q*100)
    void markPresentValues(int n, int l, int r, vector<int> &freq, int pS[n+2][101])
    {
        for(int j=1; j<=100; j++)
        {
            int found = pS[r][j];
            if(l>0) found -= pS[l-1][j];
            if(found>0) freq.push_back(j);
            
        }
    }
    vector<int> minDifference(vector<int>& v, vector<vector<int>>& que) {
        int n = v.size();
        
        //store the prefix of frequency of 1<=j<=100  
        int pS[n+2][101];
        memset(pS, 0, sizeof pS);
        pS[0][v[0]]++;
        for(int i=1; i<n; i++)
        {
            pS[i][v[i]] = 1;
            for(int j=1; j<=100; j++)
            {
                pS[i][j] += pS[i-1][j];
            }
        }
        
        vector<int> res;
        for(auto &q:que)
        {
            vector<int> freq;
            markPresentValues(n, q[0], q[1], freq, pS);
            
            //check minimum absolute difference..
            int mini = 101;
            for(int j=1; j<freq.size(); j++)
            {
                mini = min(mini, freq[j] - freq[j-1]);
            }
            mini = mini==101 ? -1 : mini;   
            res.push_back(mini);
        }
        
        return res;
    }
};