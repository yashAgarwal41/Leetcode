class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int,int> lost;
        //assigning all players loss to '0' initially..
        for(auto &it:matches)
        {
            lost[it[0]]=0;
            lost[it[1]]=0;
        }
        //calculating loss of each player..
        for(auto &it:matches)
            lost[it[1]]++;
        
        vector<int> noLost, oneLost;
        for(auto &it:lost)
        {
            if(it.second==0)    noLost.push_back(it.first);
            else if(it.second==1)   oneLost.push_back(it.first);
        }
        vector<vector<int>> res;
        res.push_back(noLost);
        res.push_back(oneLost);
        return res;
    }
};