class Solution {
public:
    bool help(int i, int n, vector<int> &powers)
    {
        if(n==0)    return true;
        if(n<0 or i>=powers.size())    return false;
        
        bool pick=false, notPick=false;
        if(n>=powers[i])    pick = help(i+1, n-powers[i], powers);
        notPick = help(i+1, n, powers);
        
        return pick or notPick;
    }
    bool checkPowersOfThree(int n) {
        vector<int> powers;
        int p=1;
        while(p<=n)
        {
            if(p==n)    return true;
            powers.push_back(p);
            p *= 3;
        }
        return help(0, n, powers);
    }
};