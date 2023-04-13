class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        while(i < popped.size()) {
            if((st.empty() || st.top() != popped[i]) && j < pushed.size()) {
                st.push(pushed[j++]);
            }
             
            else if(st.top() == popped[i]) {
                st.pop(), ++i;
            }

            else {
                break;
            }
        }
        return st.empty();
    }
};