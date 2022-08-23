class Solution {
public:
    //TC-O(n), SC-O(n)..
    string reverseWords(string s) {
        int n = s.size(), i=0;
        vector<string> v;
        string str = "";
        
        while(i<n)
        {
            if(s[i] == ' ')
            {
                if(!str.empty())    v.push_back(str);
                str = "";
                while(s[i] == ' ') i++;
            }
            else 
            {
                str += s[i];
                i++;
            }
        }
        if(!str.empty())    v.push_back(str);
        
        string ans = "";
        for(int i=v.size()-1; i>=0; i--)
        {
            ans += v[i];
            if(i>0) ans += " ";
        }
        
        return ans;
    }
};