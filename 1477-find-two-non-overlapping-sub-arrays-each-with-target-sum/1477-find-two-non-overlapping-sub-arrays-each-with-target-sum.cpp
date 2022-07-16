class Solution {
public:
    //Sliding Window..TC-O(n)..
    int minSumOfLengths(vector<int>& v, int target) {
        int n = v.size();
        vector<int> dp(n, INT_MAX); //dp[i] represent minLen of required subarray till now..
        int i=0, j=0, sum=0, ans=INT_MAX, miniLen = INT_MAX;
        
        while(i<n and j<n)
        {
            sum += v[j];
            while(sum>target)
            {
                sum -= v[i++];
            }
            
            if(sum==target)
            {
                int currLen = j-i+1;
                if(i>0 and dp[i-1]!=INT_MAX)  //if there exist a non-overlapping subarray with sum=target.
                {
                    ans = min(ans, currLen + dp[i-1]);  //update our ans to minimum..
                }
                
                miniLen = min(miniLen, currLen);    //miniLen of required subarray till now..
            }
            dp[j] = miniLen;    //update the miniLen in dp..
            j++;
        }
        return ans == INT_MAX ? -1 : ans; 
    }
};