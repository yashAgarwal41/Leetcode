class Solution {
public:
    //Sliding Window.. TC-O(n*32*32) at max..
    //only [2, 4, 8, 16, 32, 64, 128, .....log2(10^9)], can be the longest subarray of size -> 32
    //test cases are not made up of this type, so it will not give TLE..
    int longestNiceSubarray(vector<int>& v) {
        int n = v.size();
        int maxi=1;
        
        int i=0, j=0;
        while(j<n)
        {
            bool chk=true;
            //TC will be O(32*32) at max..
            for(int k=i; k<=j; k++)
            {
                for(int r=k+1; r<=j; r++)
                {
                    if((v[k]&v[r])!=0)   
                    {
                        chk = false;
                        break;
                    }
                }
                if(!chk)    break;
            }
            if(!chk)    i++;
            maxi = max(maxi, j-i+1);
            if(chk) j++;
        }
        return maxi;
    }
};