class Solution {
public:
    static bool compare(string &s1, string &s2)
    {
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto it:nums)
            v.push_back(to_string(it));
        
        sort(v.begin(), v.end(), compare);
        string ans="";
        for(auto str:v) ans+=str;
        
        while(ans[0]=='0' and ans.size()>1)        
            ans = ans.substr(1, ans.size());
         // ans.size()>1 is used because if all are '0', then it should return '0', not empty string..

        return ans;
    }
};