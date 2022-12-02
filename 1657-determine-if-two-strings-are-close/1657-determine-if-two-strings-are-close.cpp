class Solution {
public:
    //TC-O(n)..
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())  return false;
        
        vector<int> freq1(26), freq2(26);
        vector<int> found1(26), found2(26);
        for(auto &c:word1)
        {
            freq1[c-'a']++;
            found1[c-'a'] = 1;
        }
        for(auto &c:word2)
        {
            freq2[c-'a']++;
            found2[c-'a'] = 1;
        }
        sort(freq1.begin(), freq1.end());   //TC-O(26log(26))
        sort(freq2.begin(), freq2.end());
        return freq1==freq2 and found1 == found2;
    }
};