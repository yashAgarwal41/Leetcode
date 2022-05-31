class Solution {
public:
    //Using Set..
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        unordered_set<string> set;
        for(int i=0; i<=n-k; i++)
        {
            string temp=s.substr(i, k);
            set.insert(temp);
        }
        if(set.size() == 1<<k)  return true;
        return false;
    }
};