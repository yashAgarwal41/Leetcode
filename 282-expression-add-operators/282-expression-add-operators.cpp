class Solution {
public:
    //backTracking..
    int n;
    vector<string> res;
    void help(int i, long totalSoFar, long prev, const string &strAns, int &target, string &s)
    {
        if(i>=n)
        {
            if(totalSoFar == target)  res.push_back(strAns);
            return;
        }
        
        long num = 0;
        string numStr;
        for(int j=i; j<n; j++)
        {
            if(j>i and s[i]=='0')  break;   //to remove leading '0's..
            num = num*10 + s[j]-'0';
            numStr += s[j];
            if(i==0)
            {
                help(j+1, num, num, strAns + numStr, target, s);
                continue;
            }
            help(j+1, totalSoFar + num, num, strAns + "+" + numStr, target, s); //add

            help(j+1, totalSoFar - num, -num, strAns + "-" + numStr, target, s);    //subtract

            long multiplyChain = prev*num;
            help(j+1, totalSoFar - prev+ multiplyChain, multiplyChain, strAns + "*" + numStr, target, s); //multiply
        }
        
        
    }
    vector<string> addOperators(string s, int target) {
        n = s.size();
        help(0, 0, 0, "", target, s);
        
        return res;
    }
};