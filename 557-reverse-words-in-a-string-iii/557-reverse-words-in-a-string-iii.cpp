class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int left=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+left, s.begin()+i);
                left=i+1;
            }
        }
        if(s[n-1]!=' ') reverse(s.begin()+left, s.end());
        
        return s;
    }
};