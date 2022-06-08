class Solution {
public:
    bool isPalindrome(string &s)
    {
        int i=0, j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])  return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(isPalindrome(s)) return 1;
        //take a subsequence of all 'a' and remove them - 1 step
        //take a subsequence of all 'b' and remove them - 1 step
        else return 2;  
    }
};