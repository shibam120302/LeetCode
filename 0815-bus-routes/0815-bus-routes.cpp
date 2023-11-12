class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        vector<bool> visited(routes.size(), false);
        queue<int> q;
        q.push(source);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                int currentStop = q.front();
                q.pop();

                for (int routeIndex : stopToRoutes[currentStop]) {
                    if (visited[routeIndex]) {
                        continue;
                    }

                    visited[routeIndex] = true;

                    for (int nextStop : routes[routeIndex]) {
                        if (nextStop == target) {
                            return level + 1;
                        }
                        q.push(nextStop);
                    }
                }
            }

            level++;
        }

        return -1; // If target is not reachable
    }
};