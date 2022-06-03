class Solution {
public:
    //Permutations Question..TC-O(2^9)..
    bool help(int i, int sz, string s)
    {   
        if(s[0]=='0')   return false;
        int num = stoi(s);
        if(floor(log2(num)) == ceil(log2(num))) return true;
        
        bool ans = false;
        for(int j=i; j<sz; j++)
        {
            swap(s[i], s[j]);
            ans = ans or help(i+1, sz, s);
            swap(s[i], s[j]);
        }
        return ans;
    }
    
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        int sz = s.size();
        return help(0, sz, s);
    }
};