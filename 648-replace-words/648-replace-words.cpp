class Solution {
public:
    string replaceWords(vector<string>& dic, string sen) {
        int n = sen.size();
        unordered_set<string> set;
        for(auto &word:dic)    set.insert(word);
        
        string res = "";
        for(int i=0; i<n; i++)
        {
            string root = "";
            while(i<n and sen[i]!=' ')
            {
                root += sen[i];
                i++;
                if(set.count(root)) break;
            }
            res += root;
            res += " ";
            while(i<n and sen[i]!=' ')
            {
                i++;
            }
        }
        res.pop_back();
        return res;
    }
};