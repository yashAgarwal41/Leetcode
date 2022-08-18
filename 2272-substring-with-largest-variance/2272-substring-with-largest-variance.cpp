class Solution {
public:
    //Kadane's Algo (check all letters pairs (a-z)), TC-O(n*26*26)..
    int largestVariance(string s) {
        int n = s.size(), maxi=0;
        
        // choose two char for comparison, p->higher freq, q->lower freq..
        for(char p='a'; p<='z'; p++)
        {
            for(char q='a'; q<='z'; q++)
            {
                if(p==q)    continue;
                int pCnt=0, qCnt=0;
                bool qSeen = 0;
                for(auto &c:s)
                {
                    if(c==p)    pCnt++;
                    if(c==q)    qCnt++;
                    
                    if(pCnt > qCnt)
                    {
                        //at least 1 q should be there in substring..
                        if(qCnt > 0)    
                            maxi = max(maxi, pCnt - qCnt);
                        //if no q in current substring, then q must be seen before to extend the substring
                        else if(qCnt == 0 and qSeen == 1)    
                            maxi = max(maxi, pCnt - 1);
                    }
                    //else reset them with 0 and mark the qSeen as 1
                    else if(qCnt > pCnt)
                    {
                        pCnt=0, qCnt=0;
                        qSeen=1;
                    }
                }
            }
        }
        
        return maxi;
    }
};