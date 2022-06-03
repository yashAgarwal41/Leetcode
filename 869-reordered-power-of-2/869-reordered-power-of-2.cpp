class Solution {
public:
    string sortInt(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        
        string s = sortInt(n);
        for(int i=0; i<32; i++)
        {
            string powOf2Str = sortInt(1 << i);
            if(powOf2Str == s)  return true;
        }
        return false;
        
    }
};