class Solution {
public:
    //Stack..TC-O(n), SC-O(n)..
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size(), ans=0;
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(tokens[i]!="+" and tokens[i]!="-" and tokens[i]!="*" and tokens[i]!="/")
            {
                st.push(stoi(tokens[i]));
            }
            else 
            {
                if(st.size()>=2)
                {
                    int y = st.top();
                    st.pop();
                    int x = st.top();
                    st.pop();
                    if(tokens[i] == "+")    x=x+y;
                    else if(tokens[i] == "-")    x=x-y;
                    else if(tokens[i] == "*")    x=x*y;
                    else if(tokens[i] == "/")    x=x/y;
                    st.push(x);
                }
            }
        }
        
        return st.top();
    }
};