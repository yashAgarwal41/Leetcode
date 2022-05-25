class Solution {
public:
    //using stack..
    vector<int> asteroidCollision(vector<int>& v) {
        int n=v.size();
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(st.empty() || v[i]>0)  st.push(v[i]);
            else
            {
                if(v[i]<0 and st.top()<0)   st.push(v[i]);
                else 
                {
                    while(!st.empty() and st.top()>0 and st.top()<abs(v[i]))
                        st.pop();
                    if(!st.empty() and st.top() == abs(v[i]))   st.pop();
                    else if(st.empty() or st.top()<abs(v[i]))    st.push(v[i]);
                }
            }
        }
        
        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};