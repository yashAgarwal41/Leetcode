class Solution {
public:

    string frequencySort(string s) {
        int n=s.size(), freq=0;
        string ans="";
        sort(s.begin(), s.end());
        s=s+"-";    //to be safe at edge case..
        vector<pair<int, char>> v;  //stores the char with freq and then sort it..
        char c=s[0];
        
        for(int i=0; i<n+1; i++)
        {
            if(s[i]!=c)
            {
                v.push_back(make_pair(freq, c));
                freq=0;
                c=s[i];
            }
            freq++;
        }
        sort(v.begin(), v.end());
        for(auto it:v)
        {
            while(it.first)
            {
                ans+=it.second;
                it.first--;
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};