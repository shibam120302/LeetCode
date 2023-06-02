class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();
        vector<int> adj[n];
        int ans  = 0;


        

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                long long delta_x = bombs[i][0] - bombs[j][0];
                long long delta_y = bombs[i][1] - bombs[j][1];
                long long dis = (delta_x*delta_x) + (delta_y*delta_y);
                if(dis<=1ll*bombs[i][2]*bombs[i][2]){
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            vector<int> blast(n,0);
            int temp  = 0;
            queue<int> q;
            q.push(i);
            blast[i] = 1;

            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(auto it : adj[temp]){
                    if(!blast[it]){
                        q.push(it);
                        blast[it] = 1;
                    }
                }
            }

            for(int i=0;i<n;i++){
                if(blast[i]==1){
                    temp++;
                }
            }

            cout<<temp<<endl;

            ans = max(ans,temp);
        }

        return ans;

    }
};