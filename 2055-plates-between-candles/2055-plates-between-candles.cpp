class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> res;
        vector<int> candies;
        for(int i=0; i<n; i++)
            if(s[i]=='|')   candies.push_back(i);
        
        
        for(auto &q:queries)
        {
            int leftMost = lower_bound(candies.begin(), candies.end(), q[0]) - candies.begin();
            int rightMost = upper_bound(candies.begin(), candies.end(), q[1]) - candies.begin()-1;
            
            if(leftMost >= rightMost)
            {
                res.push_back(0);
                continue;
            }
            int leftInd = candies[leftMost], rightInd = candies[rightMost];
            int ans = rightInd - leftInd - (rightMost-leftMost);
            res.push_back(ans);
        }
        
        return res;
    }
};