class Solution {
public:
    //LIS(Binary search), TC_O(nlogn)
    //explained in notes..
    int Lis(vector<int> &v)
    {
        vector<int> lis;
        for(int i=0; i<v.size(); i++)
        {
            auto lb = upper_bound(lis.begin(), lis.end(), v[i]);    //non-decreasing subsequence..
            
            if(lb==lis.end())   lis.push_back(v[i]);
            else    *lb = v[i];
        }
        return lis.size();
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<k; i++)
        {
            //select the independent subsequence starting with value arr[i]
            //1st subseq -> arr[0], arr[o+k], arr[0+2k]..
            //2nd subseq -> arr[1], arr[1+k], arr[1+2k]..
            //3rd subseq -> arr[2], arr[2+k], arr[2+2k].. 
            vector<int> subsequence;
            for(int j=i; j<arr.size(); j+=k)
            {
                subsequence.push_back(arr[j]);
            }
            
            ans += subsequence.size() - Lis(subsequence);
        }
        return ans;
    }
};