class Solution {
public:
    //TC-O((n-m*30)*m*30)..
    int n, m, sz, totSize;
    bool found(int i, string &s, unordered_map<string, int> &orig)
    {
        int j=0, k=i;
        unordered_map<string, int> seen;
        
        //check for all words in 'words'
        for(j=0; j<m; j++)
        {
            string str="";
            while(str.size()<sz)    
            {
                str += s[k];
                k++;
            }
            if(orig.find(str) != orig.end())
            {
                seen[str]++;
                if(seen[str] > orig[str])
                    break;
            }
            else break;
        }
        
        if(j == m)  return true;
        else        return false;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.size(), m = words.size(), sz = words[0].size();
        totSize = m*sz;
        unordered_map<string, int> orig;
        for(auto &str:words)    orig[str]++;
        
        vector<int> res;
        for(int i=0; i<=n-totSize; i++)
        {
            if(found(i, s, orig))
                res.push_back(i);
        }
        return res;
    }
};