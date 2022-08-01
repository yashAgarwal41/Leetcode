class Solution {
public:
    //Sliding Window + queue..TC-O(n)..
    //e.g-> [2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 1]
    //       |        |           |
    //       i       q.front()    j
    //so subarrays between i to j = q.front()-i = 3-0 = 3;
    int numberOfSubarrays(vector<int>& v, int k) {
        int n = v.size();
        int i=0, j=0, cntOdd=0, ans=0;
        queue<int> q;   //stores the index of odd nos.
        while(i<n and j<n)
        {
            if(v[j]&1)
            {
                cntOdd++;
                q.push(j);  //store the index of odd no..
            }
            while(cntOdd>k)
            {
                if(v[i]&1)
                {
                    cntOdd--;
                    q.pop();    //pop the index of odd no..
                }
                i++;
            }
            if(cntOdd==k)   ans += q.front()-i+1;
            j++;
        }
        return ans;
    }
};