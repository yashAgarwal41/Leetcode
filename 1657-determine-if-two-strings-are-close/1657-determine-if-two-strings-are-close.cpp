class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n!=m)    return false;
        vector<int> freq1(26), freq2(26);
        for(auto &c:word1)  freq1[c-'a']++;
        for(auto &c:word2)  freq2[c-'a']++;
        
        map<int, int> map1, map2;
        for(int i=0; i<26; i++)
        {
            if(freq1[i]>0 and freq2[i]==0 or freq1[i]==0 and freq2[i]>0)  return false;
            map1[freq1[i]]++;
            map2[freq2[i]]++;
        }
        if(map1==map2)  return true;
        else return false;
    }
};

// a-1, b-1, c-1
// a-1, b-1, c-1

//a-2, b-3, c-1
//a-1, b-2, c-3

// a-3, b-4, c-2, d-2, e-5, f-5
// a-6, b-2, c-3, d-3, e-4, f-4