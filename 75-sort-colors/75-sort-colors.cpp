class Solution {
public:
    //DNF algo..TC-O(n), SC-O(1)..
    // v[0, ...low-1]->0
    // v[low, ...mid]->1
    // v[high+1, ...n]->2
    void sortColors(vector<int>& v) {
        int n = v.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high)
        {
            if(v[mid]==0)
            {
                swap(v[low], v[mid]);
                low++;  //0 placed at low, move ahead..
                mid++;  //definitely, either '0' or '1' is placed at mid, not '2'..
            }
            else if(v[mid]==1)  mid++;
            else if(v[mid]==2)
            {
                swap(v[mid], v[high]);
                high--; //2 placed at high, move leftwards..
            }
        }
    }
};