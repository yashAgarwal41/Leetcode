class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> res;
        vector<int> candies, plates(n, 0);
        plates[0] = (s[0]=='*');
        if(s[0]=='|')   candies.push_back(0);
        for(int i=1; i<n; i++)
        {
            if(s[i]=='|')   candies.push_back(i);
            plates[i] = plates[i-1] + (s[i]=='*');
        }
        
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
            res.push_back(plates[rightInd] - plates[leftInd]);
        }
        
        return res;
    }
};