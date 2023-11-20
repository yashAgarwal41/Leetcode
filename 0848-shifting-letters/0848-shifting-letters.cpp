class Solution {
public:
    //start from last, TC-O(n)
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long sum = 0;
        for(int i=n-1; i>=0; i--)
        {
            sum += shifts[i]+0LL;
            int shift = (s[i]-'a' + sum + 0LL)%26;
            s[i] = 'a' + shift;
        }
        
        return s;
    }
};

