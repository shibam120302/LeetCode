class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // Initialize the answer vector to store groups of people
        vector<vector<int>> groupsOfPeople;

        // Create a map to store people's IDs grouped by their desired group sizes
        map<int, vector<int>> groupMap;

        // Iterate through the groupSizes array
        for (int personID = 0; personID < groupSizes.size(); personID++) {
            int desiredGroupSize = groupSizes[personID];

            // Add the current person's ID to the corresponding group
            groupMap[desiredGroupSize].push_back(personID);

            // Check if the group is complete (i.e., has the desired size)
            if (groupMap[desiredGroupSize].size() == desiredGroupSize) {
                // Add the complete group to the answer vector
                groupsOfPeople.emplace_back(move(groupMap[desiredGroupSize]));

                // Clear the group as it's been added to the answer
                groupMap[desiredGroupSize].clear();
            }
        }

        // Return the answer containing grouped people
        return groupsOfPeople;
    }
};