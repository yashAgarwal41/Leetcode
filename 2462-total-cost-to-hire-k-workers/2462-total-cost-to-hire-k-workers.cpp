class Solution {
public:
    //Priority Queue + 2 pointers..
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size(), i=0, j=n-1;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        long long ans = 0;
        while(k>0 and i<=j)
        {
            if(pq1.size()<candidates)  
            {
                pq1.push(costs[i]);
                i++;
                if(i>j) break;
            }
            if(pq2.size()<candidates)
            {
                pq2.push(costs[j]);
                j--;
            }
            if(pq1.size() == pq2.size() and pq1.size() == candidates)
            {
                if(pq1.top() == pq2.top())
                {
                    if(costs[i] <= costs[j])
                    {
                        ans += pq1.top();
                        pq1.pop();
                    }
                    else 
                    {
                        ans += pq2.top();
                        pq2.pop();
                    }
                }
                 else if(pq1.top()<pq2.top())
                {
                    ans += pq1.top();
                    pq1.pop();
                }
                else 
                {
                    ans += pq2.top();
                    pq2.pop();
                }
                k--;
            }
        }
        while(k>0)
        {
            if(pq1.empty())
            {
                ans += pq2.top();
                pq2.pop();
            }
            else if(pq2.empty())
            {
                ans += pq1.top();
                pq1.pop();
            }
            else if(pq1.top()<=pq2.top())
            {
                ans += pq1.top();
                pq1.pop();
            }
            else 
            {
                ans += pq2.top();
                pq2.pop();
            }
            k--;
        }
        return ans;
    }
};