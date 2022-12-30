class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> v(n);
        stack<pair<int,int>> st; // {temperature , index};

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<temperatures[i]){
                v[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
        }

        while(!st.empty()){
            v[st.top().second]=0;
            st.pop();
        }
        
        return v;
    }
};