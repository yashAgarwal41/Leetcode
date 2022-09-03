class Solution {
public:
    //Backtracking..
    void help(int i, int num, int n, int k, vector<int> &ans)
    {
        if(i>=n)
        {
            ans.push_back(num);
            return;
        }
        
        for(int j=0; j<=9; j++)
        {
            if(i == 0 and j==0)   continue;
            else if(i==0)
                help(i+1, j, n, k, ans);
            else 
            {
                int r = num%10;
                if(abs(j-r) == k)
                {
                    help(i+1, num*10 + j, n, k, ans);
                }
            }
            
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        help(0, 0, n, k, ans);
        return ans;
    }
};