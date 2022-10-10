class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(n==1)    return "";
        
        bool done = false;
        for(int i=0; i<n; i++)
        {
            if(s[i]!='a' and i!=n/2)
            {
                s[i] = 'a'; 
                done = true;    break;
            }
        }
        if(!done)   s[n-1] = 'b';
        return s;
    }
};