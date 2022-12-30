class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(auto s:tokens)
        {
            if(s=="+" || s=="-"|| s=="/"|| s=="*")
            {
                long x=st.top();
                st.pop();
                long y=st.top();
                st.pop();
                if(s == "+")
                {
                    st.push(y+x);
                }
                else if(s == "-")
                {
                    st.push(y-x);
                }
                else if(s == "*")
                {
                    st.push(y*x);
                }
                else
                {
                    st.push(y/x);
                }
            }
            else
            {
                int n=stoi(s);
                st.push(n);
            }
        }
        return st.top();
    }
};