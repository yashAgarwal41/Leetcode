class Solution {
public:
    //Stack
    int longestValidParentheses(string s) {
        int n=s.size();
        int maxi=0;
        stack<int> st;  //stores all starting indices of valid parenthesis..
        st.push(-1);
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')   st.push(i);
            else 
            {
                st.pop();
                if(st.empty())   st.push(i);    //start with next index..
                maxi = max(maxi, i-st.top());
            }
        }
        
        return maxi;
    }
};