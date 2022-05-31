class Solution {
public:
    //DP..TC-O(n), SC-O(n)..
    int wiggleMaxLength(vector<int>& v) {
        int n=v.size();
        vector<int> dp(n, -1);
        //dp will contain the upward peak or downward peak or constant peak..
        for(int i=0; i<n-1; i++)
        {
            if(v[i+1]>v[i]) dp[i] = 1;  //upward peak
            else if(v[i+1]<v[i])    dp[i]=0;    //downward peak
            else dp[i] = -1;    //constant peak(equal elements)
        }
        int ans=0, prev=-1;
        for(int i=0; i<n-1; i++)
        {
            if(dp[i]==-1)   continue;   //equal elements..
            int curr = dp[i];   
            if(curr!=prev)  //peak direction changed..meand sign changed..
            {
                ans++;
                prev=curr; 
            }
        }
        return ans+1;
    }
};