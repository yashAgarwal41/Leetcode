class Solution {
public:
    int sz;
    string smallestFirst(string s, int x)   //for negative no
    {
        char dig = '0'+x;
        string res="-";
        int i=1;
        while(i<s.size())
        {
            if(s[i] > dig)
            {
                res += dig;
                break;
            }
            res+=s[i++];
        }
        if(i==sz)   res+=dig;
        else res += s.substr(i);
        return res;
    }
    string largestFirst(string s, int x)    //for positive no
    {
        char dig = '0' + x;
        string res="";
        int i=0;
        while(i<s.size())
        {
            if(s[i] < dig)
            {
                res += dig;
                break;
            }
            res+=s[i++];
        }
        if(i==sz)   res+=dig;
        else res += s.substr(i);
        return res;
    }
    string maxValue(string s, int x) {
        sz = s.size();
        if(s[0]=='-')
            return smallestFirst(s, x);
        return largestFirst(s, x);
    }
};