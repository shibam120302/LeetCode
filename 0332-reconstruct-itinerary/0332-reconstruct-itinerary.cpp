class Solution {
public:
    #define pq priority_queue<string,vector<string>,greater<string>>
    map<string,pq>mp;
    vector<string>ans;
    void dfs(string start){
        if(mp[start].size()==0){
            ans.push_back(start);
            return;
        }

        auto &s=mp[start];

        while(!s.empty()){
            auto temp=s.top();
            s.pop();

            dfs(temp);
        }   
        ans.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mp.clear();
        ans.clear();
        
        for(auto i:tickets){
            mp[i[0]].push(i[1]);
        }

        dfs("JFK");

        reverse(ans.begin(),end(ans));

        return ans;
    }
};