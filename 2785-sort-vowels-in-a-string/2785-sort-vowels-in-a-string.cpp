class Solution {
public:
    string vowels = "aeiouAEIOU";
    string sortVowels(string s) {
        int n = s.size();
        string vow;
        for(int i=0; i<n; i++)
        {
            if(vowels.find(s[i]) < vowels.size())   
                vow.push_back(s[i]);
        }
        sort(vow.begin(), vow.end());
        
        int i=0;
        for(auto &c:s)
        {
            if(vowels.find(c) < vowels.size())
                c = vow[i++];
        }
        return s;
    }
};