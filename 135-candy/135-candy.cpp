class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> v(n, 1);
        for(int i=0; i<n; i++)
        {
            if(i>0 and i<n-1)
            {
                if(rat[i]>rat[i-1] and v[i]<=v[i-1]) v[i] = v[i-1]+1;
                else if(rat[i]>rat[i+1] and v[i]<=v[i+1])   
                {
                    // if(rat[i]==rat[i-1])    
                        v[i]=v[i+1]+1;
                    // else v[i] = max(v[i-1], v[i+1])+1;
                }
            }
            else if(i<n-1)  //at i=0..
            {
                if(rat[i]>rat[i+1] and v[i]<=v[i+1])
                {
                    v[i]=v[i+1]+1;
                }
            }
            else if(i>0)    //at i=n-1..
            {
                if(rat[i]>rat[i-1] and v[i]<=v[i-1])
                    v[i]=v[i-1]+1;
            }
        }
        reverse(rat.begin(), rat.end());
        reverse(v.begin(), v.end());
        for(int i=0; i<n; i++)
        {
            if(i>0 and i<n-1)
            {
                if(rat[i]>rat[i-1] and v[i]<=v[i-1]) v[i] = v[i-1]+1;
                else if(rat[i]>rat[i+1] and v[i]<=v[i+1])   
                {
                    // if(rat[i]==rat[i-1])    
                        v[i]=v[i+1]+1;
                    // else v[i] = max(v[i-1], v[i+1])+1;
                }
            }
            else if(i<n-1)  //at i=0..
            {
                if(rat[i]>rat[i+1] and v[i]<=v[i+1])
                {
                    v[i]=v[i+1]+1;
                }
            }
            else if(i>0)    //at i=n-1..
            {
                if(rat[i]>rat[i-1] and v[i]<=v[i-1])
                    v[i]=v[i-1]+1;
            }
        }
        // for(auto it:v)  cout<<it<<" ";
        // cout<<endl;
        int sum = accumulate(v.begin(), v.end(), 0);
        return sum;
    }
};