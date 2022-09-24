class Solution {
public:
    //TC-O(n*logn*10)
    //frequency of the lexicographically smallest character
    int frequency(string &str)
    {
        int freq=0;
        char mn = 'z';
        for(auto &c:str)
        {
            if(c == mn) freq++;
            else if(c < mn)
            {
                freq=1;  mn = c;
            }
        }
        return freq;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) 
    {
        multiset<int> set;
        vector<int> v, res;
        
        for(auto &str:words)    set.insert(frequency(str));
        for(auto it:set)    v.push_back(it);
        for(auto q:queries)
        {
            int freq = frequency(q);
            int ub = upper_bound(v.begin(), v.end(), freq) - v.begin();
            res.push_back(v.size()-ub);
        }
        return res;
    }
};