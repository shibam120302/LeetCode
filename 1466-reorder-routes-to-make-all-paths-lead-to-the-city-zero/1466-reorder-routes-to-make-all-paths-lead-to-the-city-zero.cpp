class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>&adj, vector<bool>& visited, int& ans, int currNode)
    {
        visited[currNode] = true;
        for (pair<int, int>adjNode : adj[currNode])
        {
            //Curr = source, Next = adjNode.first
            if (visited[adjNode.first]) continue;
            
            //adjNode.second == 1 means that there is a real edge from 'Curr' to 'Next'
            bool isEdgeOutward = (adjNode.second == 1); 
            if (isEdgeOutward) ans++; //but we want edge to come from 'Next' to 'Curr', so change direction 
            dfs(adj, visited, ans, adjNode.first);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int, int>>>adj(n);
        for(vector<int>connection : connections)
        {
            adj[connection[0]].push_back({connection[1], 1}); //real edge 
            adj[connection[1]].push_back({connection[0], -1}); //false edge made for traversal
        }
        //===========================================================
        vector<bool>visited(n, false);
        int ans = 0;
        dfs(adj, visited, ans, 0);
        return ans;
    }
};