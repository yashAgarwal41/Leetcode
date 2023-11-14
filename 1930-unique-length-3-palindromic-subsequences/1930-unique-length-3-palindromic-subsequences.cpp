class Solution {
public:
    //prefixSum, TC-O(n*26), SC-O(n*26)
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> pS(26, vector<int> (n, 0));
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j == 0)  pS[i][j] = 0;
                else pS[i][j] = pS[i][j-1];
                
                int c = s[j] - 'a';
                if(i == c)  pS[i][j]++;
            }
        }
        
        int ans = 0;
        for(int i=0; i<26; i++)
        {
            if(pS[i][n-1] <= 1)  continue;
            int l = lower_bound(pS[i].begin(), pS[i].end(), 1) - pS[i].begin();
            int r = lower_bound(pS[i].begin(), pS[i].end(), pS[i][n-1]) - pS[i].begin();
            int cnt = pS[i][n-1];
            int total = (r - l - 1) - (cnt-2);
            if(cnt > 2) total += 1;
            
            for(int j=0; j<26; j++)
            {
                if(i == j)  continue;
                int cnt2 = pS[j][r] - pS[j][l];
                if(cnt2 > 1)  total -= (cnt2-1);
            }
            ans += total;
        }
        
        return ans;
    }
};