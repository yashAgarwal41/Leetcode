class Solution {
public:
    //2 pointers..
    vector<int> twoSum(vector<int>& v, int target) {
        int l=0, r=v.size()-1;
        vector<int> res;
        while(l<r)
        {
            if(v[l] + v[r] == target)
            {
                res.push_back(l+1);
                res.push_back(r+1);
                break;
            }
            else if(v[l] + v[r] > target)
                r--;
            else l++;
        }
        return res;
    }
};