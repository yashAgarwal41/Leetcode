class Solution {
public:
    //TC-O(n)..Move from backside..
    string finalString(string s, int n)
    {
        int cnt = 0;
        string ans = "";
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='#')
                cnt++;
            else if(cnt>0)
                cnt--;
            else ans+=s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        return finalString(s, n) == finalString(t, m);
    }
};