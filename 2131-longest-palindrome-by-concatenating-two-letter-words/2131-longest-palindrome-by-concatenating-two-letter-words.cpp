class Solution {
public:
    int longestPalindrome(vector<string>& v) {
        int n = v.size();
        unordered_map<string, int> map;
        for(auto &str : v)
        {
            map[str]++;
        }
        
        int ans = 0;
        bool oddCheck = false;
        for(auto &it : map)
        {
            string str = it.first;
            if(str[0] != str[1])
            {
                string rev = "";
                rev += str[1];
                rev += str[0];
                if(map.count(rev))
                {
                    ans += 2*min(map[str], map[rev]);
                }
            }
            else 
            {
                ans += 4*(map[str]/2);
                if(map[str]%2)  oddCheck = true;
            }
        }
        if(oddCheck) ans += 2;
        return ans;
    }
};