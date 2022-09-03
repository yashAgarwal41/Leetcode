class Solution {
public:
    //Backtracking..TC-O(2^n)
    int n;
    void help(int i, int n, int k, int num, vector<int> &res)
    {
        if(i>=n)
        {
            res.push_back(num);
            return;
        }
        
        if(i==0)
        {
            for(int j=1; j<=9; j++)  help(i+1, n, k, j, res);
        }
        else
        {
            int low = num%10 - k;
            int high = num%10 + k;

            if(low>=0 and low<=9)   help(i+1, n, k, num*10 + low, res);
            if(high>=0 and high<=9 and low!=high)   help(i+1, n, k, num*10 + high, res);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        help(0, n, k, 0, res);
        return res;
    }
};