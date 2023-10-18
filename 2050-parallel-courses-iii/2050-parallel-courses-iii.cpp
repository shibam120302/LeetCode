class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<int> maxTime(n, 0);

        for (const vector<int>& edge : relations) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            indegree[edge[1] - 1]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
            maxTime[i] = time[i];
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        int ans = 0;

        for (int node = 0; node < n; node++) {
            ans = max(ans, maxTime[node]);
        }

        return ans;
    }
};
