class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int j = 1;
        for(int i=0; i<target.size(); i++)
        {
            while(j < target[i])
            {
                res.push_back("Push");
                res.push_back("Pop");
                j++;
            }
            res.push_back("Push");
            j++;
        }
        return res;
    }
};