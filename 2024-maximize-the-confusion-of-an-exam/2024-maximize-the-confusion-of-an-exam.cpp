class Solution {
public:
    //Sliding Window..TC-O(n), SC-O(1)..
    // maxi = max(max 'T' together, max 'F' together)..
    int maxConfuse(string &s, int k)
    {
        int maxi = 1, i = 0, j = 0, n = s.size();
        while(i<n and j<n)
        {
            if(s[j]=='F')
            {
                k--;
                while(k<0)
                {
                    k += s[i]=='F';
                    i++;
                }
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int maxi;
        //convert 'F' to 'T' and check maximum consecutives..
        maxi = maxConfuse(s, k);    //1st call..
        
        //convert 'T' to 'F' and check maximum consecutives..
        //so to use the same function again, we just flipped the answers and then check for 'F' to 'T'..
        for(auto &c : s)
        {
            if(c == 'T')    c='F';
            else c = 'T';
        }
        
        maxi = max(maxi, maxConfuse(s, k)); //2nd call..
        return maxi;
    }
};