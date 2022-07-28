class Solution {
public:
    //Greedy..TC-O(n)
    //Count no of zeroes and the position of the 1st zero..
    //atmost 1 zero will be there in required ans..
    // 01110 -> 10111   , cntZ=2
    // 011100 -> 110111     cntZ=3
    // 0111000 -> 1110111   cntZ=4
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int cntZ=0;
        for(auto &b : binary)   cntZ += b=='0';
        string ans(n, '1');
        for(int i=0; i<n; i++)
        {
            if(binary[i]=='0')
            {
                ans[i+cntZ-1] = '0';
                break;
            }
        }
        return ans;
    }
};