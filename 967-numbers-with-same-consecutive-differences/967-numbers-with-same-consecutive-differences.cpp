class Solution {
public:
    //Backtracking..
    int n;
    void help(int i, int n, int k, string ans, vector<int> &res)
    {
        if(i>=n)
        {
            int num = stoi(ans);
            res.push_back(num);
            return;
        }
        
        for(int j=0; j<=9; j++)
        {
            if(i==0 and j==0)   continue;
            if(i==0)
                help(i+1, n, k, ans + to_string(j), res);
            else 
            {
                int prev = ans[i-1] - '0';
                if(abs(j - prev) == k)
                    help(i+1, n, k, ans + to_string(j), res);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string ans = "";
        vector<int> res;
        help(0, n, k, ans, res);
        return res;
    }
};