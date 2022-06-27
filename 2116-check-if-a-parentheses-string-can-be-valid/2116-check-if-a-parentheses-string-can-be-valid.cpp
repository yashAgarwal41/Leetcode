class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size(), cnt=0;
        if(n%2) return 0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' or locked[i]=='0') cnt++;
            else cnt--;
            if(cnt<0)   return false;
        }
        cnt=0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]==')' or locked[i]=='0') cnt++;
            else cnt--;
            if(cnt<0)   return false;
        }
        return true;
    }
};