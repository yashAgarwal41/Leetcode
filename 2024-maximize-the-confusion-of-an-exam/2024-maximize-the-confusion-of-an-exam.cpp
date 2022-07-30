class Solution {
public:
    //Sliding Window..TC-O(n), SC-O(1)..
    // maxi = max(max 'T' together, max 'F' together)..
    int maxConfuse(string &s, int k, char convert)
    {
        int maxi = 1, i = 0, j = 0, n = s.size();
        while(i<n and j<n)
        {
            if(s[j]==convert)
            {
                k--;
                while(k<0)
                {
                    k += s[i]==convert;
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
        //convert 'T' to 'F' and check maximum consecutives..
        
        maxi = max(maxConfuse(s, k, 'F'), maxConfuse(s, k, 'T')); 
        return maxi;
    }
};