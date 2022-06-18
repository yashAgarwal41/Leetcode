class WordFilter {
public:
    //Using Hashmap..TC-O(n*10*10)..
    unordered_map<string, int> map;
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            string curr = words[i];
            int sz = curr.size();
            for(int j=0; j<=sz; j++)
            {
                string pre = curr.substr(0, j);
                string suf = "";
                for(int k = sz-1; k>=0; k--)
                {
                    suf = curr[k] + suf;
                    map[pre + "#" + suf] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string str = prefix + "#" + suffix;
        if(map.find(str)==map.end())    return -1;
        else return map[str];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */