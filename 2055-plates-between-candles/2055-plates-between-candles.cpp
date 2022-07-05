class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> res;
        vector<int> candies(n, 0), plates(n, 0);
        candies[0] = (s[0]=='|');
        plates[0] = (s[0]=='*');
        
        for(int i=1; i<n; i++)
        {
            candies[i] = candies[i-1] + (s[i]=='|');
            plates[i] = plates[i-1] + (s[i]=='*');
        }
        for(auto &it : queries)
        {
            int left = it[0], right= it[1];
            int leftMost, rightMost;
            if((left>0 and candies[left]>candies[left-1]) or (left==0 and candies[left]==1))
                leftMost = left;
            else leftMost = upper_bound(candies.begin(), candies.end(), candies[left]) - candies.begin();
            
            rightMost = lower_bound(candies.begin(), candies.end(), candies[right]) - candies.begin();
            
            if(leftMost >= right or rightMost<=left)    res.push_back(0);
            else{
               res.push_back(plates[rightMost] - plates[leftMost]);
            }
        }
        
        return res;
    }
};