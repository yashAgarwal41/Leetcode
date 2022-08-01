class Solution {
public:
    //Sliding Window..TC-O(n)..
    //In this, do not count the characters inside window
    //instead count the characters outside the window..
    //If outside the window, charcaters condition satisfied, take ans and shrink the window..
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        for(auto c:s) 
        {
            map[c]++;
        }
        int i=0, j=0, k=n/4, mini=INT_MAX;
        while(i<n and j<n)
        {
            map[s[j]]--;
            while(i<n and map['Q']<=k and map['W']<=k and map['E']<=k and map['R']<=k)
            {
                mini = min(mini, j-i+1);
                map[s[i]]++;
                i++;
            }
            j++;
        }
        return mini;
    }
};