class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // Create a min heap to store the costs of workers along with their indices
        // The pair is defined as (cost, index), and the heap is sorted in ascending order of costs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        // Initialize the total cost to 0
        long long ans = 0;

        // Get the total number of workers
        int n = costs.size();

        // Set the left and right pointers to the start and end of the array
        int l = 0, r = n - 1;

        // Set the initial left and right indices for candidate selection
        int il = candidates, ir = n - candidates;

        // Iterate for each hiring session
        for (int i = 0; i < k; i++) {
            // Choose the workers from the left side
            for (; l < il; l++) {
                // If the left pointer exceeds the right pointer, break the loop
                if (l >= r)
                    break;
                // Push the worker's cost and index into the min heap
                heap.push({costs[l], l});
            }

            // Choose the workers from the right side
            for (; r >= ir; r--) {
                // If the right pointer becomes smaller than the left pointer, break the loop
                if (l > r)
                    break;
                // Push the worker's cost and index into the min heap
                heap.push({costs[r], r});
            }

            // Add the lowest-cost worker's cost to the total cost
            ans += heap.top().first;

            // Update the indices for the next session
            if (heap.top().second < il)
                il++;
            else
                ir--;

            // Remove the chosen worker from the heap
            heap.pop();
        }

        // Return the total hiring cost
        return ans;
    }
};
