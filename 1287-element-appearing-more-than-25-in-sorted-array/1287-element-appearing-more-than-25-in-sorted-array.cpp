class Solution {
public:
    // Function to find an integer that appears more than 25% of the length of the input array
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> counts; // Store the count of each element
        for (int num : arr) {
            counts[num]++; // Count occurrences of each element in the array
        }
        
        int target = arr.size() / 4; // Threshold to check for the required frequency
        
        // Iterate through the counts map to find the special integer
        for (auto& [key, value] : counts) {
            if (value > target) {
                return key; // Return the integer that appears more than 25% of the time
            }
        }
        
        return -1; // If no such integer found, return -1
    }
};
