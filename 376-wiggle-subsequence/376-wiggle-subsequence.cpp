class Solution {
public:
    //sign-> 0:+, 1:-
    int dp[1001][1001][3];
    int help(int i, int prev, int sign, vector<int> &v)
    {
        if(i>=v.size()) return 0;
        if(prev!=-1 and dp[i][prev][sign]!=-1)  return dp[i][prev][sign];
        
        int take = INT_MIN;
        if(prev==-1 or sign==2 or v[i]-v[prev]!=0)
        {
            //not chosen a single element..
            if(prev == -1)
            {
                take = help(i+1, i, sign, v) + 1;
            }
            else if(v[i]-v[prev]!=0)
            {   
                //if choosen only single element..
                if(sign==2)
                {
                    sign = v[i]-v[prev]>0 ? 1 : 0;
                    take = help(i+1, i, sign, v) + 1;
                }
                //if chosen multiple elements till now..
                else 
                {
                    char newSign = v[i]-v[prev]>0 ? 1 : 0;
                    if(sign!=newSign)
                        take = help(i+1, i, newSign, v) + 1;
                }
            }
        }
        
        int notTake = help(i+1, prev, sign, v);
        if(prev==-1)   return max(take, notTake);
        else return dp[i][prev][sign] = max(take, notTake);
    }
    int wiggleMaxLength(vector<int>& v) {
        int n=v.size();
        memset(dp, -1, sizeof dp);
        return help(0, -1, 2, v);
    }
};