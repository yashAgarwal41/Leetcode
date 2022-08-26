class Solution {
public:
    //Backtracking..
    int n;
    void help(int i, int n, int k, int num, vector<int> &res)
    {
        if(i>=n)
        {
            res.push_back(num);
            return;
        }
        
        for(int j=0; j<=9; j++)
        {
            if(i==0 and j==0)   continue;
            if(i==0)
                help(i+1, n, k, j, res);
            else 
            {
                int prev = num%10;
                if(abs(j - prev) == k)
                    help(i+1, n, k, num*10 + j, res);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        help(0, n, k, 0, res);
        return res;
    }
};