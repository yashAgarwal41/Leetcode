class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i=0; i<v.size(); i++)
        {
            int val2 = target-v[i];
            auto it = m.find(val2);
            if(it==m.end()) m[v[i]] = i;
            else
            {
                res.push_back(it->second+1);
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};