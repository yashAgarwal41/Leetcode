class Solution {
public:
    string multiply(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (s1 == "0" || s2 == "0") return "0";
        vector<int> res(n+m, 0);
        for(int i=n-1; i>=0; i--)
        {
            int carry=0;
            for(int j=m-1; j>=0; j--)
            {
                res[i+j+1] += (s1[i]-'0')*(s2[j]-'0');
                res[i+j] += res[i+j+1]/10;
                res[i+j+1] %= 10;
            }
        }
        string ans="";
        int i=0;
        while(i<res.size() and res[i]==0)   i++;
        while(i<res.size()) ans += res[i++]+'0';
        
        return ans;
    }
};