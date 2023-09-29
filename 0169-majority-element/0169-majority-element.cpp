class Solution {
public:
    //Moore's voting algo', TC-O(n), SC-O(1)..
    //since major > n/2. So at the end of the for loop cnt >= 1 always...
    int majorityElement(vector<int>& v) {
        int n = v.size(), cnt=0, major;
        for(int i=0; i<n; i++)
        {
            if(cnt == 0)
            {
                major = v[i];
                cnt++;
            }
            else if(major != v[i])  cnt--;
            else cnt++;
        }
        return major;
    }
};