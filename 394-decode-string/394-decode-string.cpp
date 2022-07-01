class Solution {
public:
    string decode(string s, int &i)
    {
        string res = "";
        int n = s.size();
        while(i<n and s[i]!=']')
        {
            if(isdigit(s[i]))
            {
                int num = 0;
                while(i<n and isdigit(s[i]))
                    num = num*10 + (s[i++]-'0');
                i++;    //for [ bracket..
                string decoded = decode(s, i);
                i++;    //for ] bracket..
                
                while(num-->0)
                    res += decoded;
            }
            else 
                res += s[i++];
        }
        
        return res;
    }
    string decodeString(string s) {
        int i=0;
        return decode(s, i);
    }
};