class Solution {
public:
    // Function to perform depth-first search to find a path from source to destination
    bool solve(vector<vector<int>>& graph, int source, int destination, vector<int>& visited) {
        // If source and destination are the same, a path is found
        if (source == destination)
            return true;
        
        // Mark the current node as visited
        visited[source] = 1;
        
        // Traverse through all adjacent vertices of the current vertex
        for (auto& neighbor : graph[source]) {
            // If the neighbor is not visited, recursively search for a path
            if (!visited[neighbor]) {
                if (solve(graph, neighbor, destination, visited))
                    return true; // If a path is found, return true
            }
        }
        return false; // No path found from source to destination
    }
    
    // Function to determine if a valid path exists from source to destination
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create an adjacency list representation of the graph
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Initialize a vector to keep track of visited vertices
        vector<int> visited(n, 0);
        
        // Call the helper function to find a path from source to destination
        return solve(graph, source, destination, visited);
    }
};
