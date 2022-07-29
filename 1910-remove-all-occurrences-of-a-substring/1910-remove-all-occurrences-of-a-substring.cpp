class Solution {
public:
    //TC-O(n*n)
    int check(string &s, string &part, int repeat)
    {
        repeat = 0;
        int n = s.size(), m = part.size();
        int i = 0, j = m-1;
        string temp = "";
        while(i<n and j<n)
        {
            bool found=1;
            temp = s.substr(i, m);
            if(j-i+1 == m)  //if substringWindow of size 'm' is formed..
            {
                if(temp == part)
                {
                    repeat = 1; //break it abd again repeat from starting..
                    string st = s.substr(0, i);
                    string en = s.substr(j+1);
                    s = st + en;
                    n = s.size();
                    break;
                }
            }
            i++;    j++;
        }
        return repeat;
    }
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();
        if(m>n) return s;
        if(s == part)   return "";
        
        bool repeat = 1; //no occurence of part exist in s after some operations.. 
        
        while(repeat and s.size()>=m)
        {
            repeat = check(s, part, repeat);
        }
        return s;
    }
};