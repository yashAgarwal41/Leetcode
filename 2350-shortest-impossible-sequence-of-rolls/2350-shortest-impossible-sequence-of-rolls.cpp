class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_map<int, int> mmap;
        int miniLen = 0, cnt=0;
        for(auto &it : rolls)
        {
            mmap[it]++;
            if(mmap[it]==1) cnt++;
            if(cnt==k)  //if subsequence of (1,2,..k) is made
            {
                mmap.clear();   
                miniLen++;  //atLeast subsequences of miniLen can be made
                cnt=0;  
            }
        }
        return miniLen+1;   //upto miniLen length subsequences can be taken from rolls..
    }
};