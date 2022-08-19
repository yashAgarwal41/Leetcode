class Solution {
public:
    //Hashmap, TC-O(n), SC-O(n)
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
//         priority_queue<pair<int, int>> pq;
//         unordered_map<int, int> freqMap;
//         for(auto it:nums)   freqMap[it]++;
        
//         for(auto &it:freqMap)   pq.push({it.first, it.second});
//         if(pq.size()<3) return false;
        
//         int prev=pq.top().first+1, prevFreq = pq.top().second, cnt=0;
//         while(!pq.empty())
//         {
//             if(pq.top().first == prev-1)
//             {
//                 int currFreq = pq.top().second;
//                 if(prevFreq > currFreq)   return false;
//                 cnt++;
//                 currFreq = currFreq-prevFreq;
//                 prevFreq=currFreq;
//             }
//         }
        //freq stores the current freq of nums[i]..
        //last stores the freq of consecutive subsequences ending with nums[i]..
        unordered_map<int, int> freq, last;
        for(auto it:nums)   freq[it]++;
        
        for(auto it:nums)
        {
            if(freq[it] == 0)   continue;
            
            //check is there any subsequence ending with 'it-1', if so then attached 'it' to that
            if(last[it-1] > 0)  
            {
                //now, that subsequence ends with 'it'..
                last[it-1]--;   
                last[it]++; 
            }
            else 
            {
                //start a new subsequence with 'it' if 'it+1' and 'it+2' exists..
                if(freq[it+1] > 0 and freq[it+2]>0)
                {
                    freq[it+1]--;
                    freq[it+2]--;
                    last[it+2]++;   //this subsequence ends with 'it+2'
                }
                else return false;
            }
            freq[it]--;
        }
        
        return true;
    }
};