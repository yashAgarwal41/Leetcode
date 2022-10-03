class Solution {
public:
    //Lambda Sort
    string rankTeams(vector<string>& votes) {
        int n = votes.size(), m = votes[0].size();
        if(n == 1)  return votes[0];
        vector<vector<int>> freq(26, vector<int> (26, 0));
        for(auto &vote : votes)
        {
            for(int i=0; i<m; i++)
            {
                freq[vote[i]-'A'][i]++;
            }
        }
        
        string res = votes[0];
        sort(res.begin(), res.end(), [&](char &a, char &b)
             {
                 if(freq[a-'A'] == freq[b-'A']) return a<b;
                 else return freq[a-'A'] > freq[b-'A'];
             });
        return res;
    }
};
//A-5, 0, 0
//B-0, 2, 3
//C-0, 3, 2
//ACB

//W-1 0 0 1
//X-1 1 0 0 
//Y-0 1 1 0
//Z-0 0 1 1

// X W Y Z