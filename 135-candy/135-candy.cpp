class Solution {
public:
    //Greedy..TC-O(2*n), SC-O(n)..
    void distributeCandies(int &n, vector<int> &rat, vector<int> &candies)
    {
        for(int i=0; i<n; i++)
        {
            if(i>0 and i<n-1)
            {
                if(rat[i]>rat[i-1] and candies[i]<=candies[i-1]) 
                    candies[i] = candies[i-1]+1;
                else if(rat[i]>rat[i+1] and candies[i]<=candies[i+1])   
                        candies[i]=candies[i+1]+1;
            }
            else if(i<n-1)  //at i=0..
            {
                if(rat[i]>rat[i+1] and candies[i]<=candies[i+1])
                    candies[i]=candies[i+1]+1;
                
            }
            else if(i>0)    //at i=n-1..
            {
                if(rat[i]>rat[i-1] and candies[i]<=candies[i-1])
                    candies[i]=candies[i-1]+1;
            }
        }
    }
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> candies(n, 1);
        
        distributeCandies(n, rat, candies);   //first distribute from left to right
        reverse(rat.begin(), rat.end());
        reverse(candies.begin(), candies.end());
        distributeCandies(n, rat, candies);     //then check and distribute from right to left(i.e, reversed)
        
        int sum = accumulate(candies.begin(), candies.end(), 0);
        return sum;
    }
};