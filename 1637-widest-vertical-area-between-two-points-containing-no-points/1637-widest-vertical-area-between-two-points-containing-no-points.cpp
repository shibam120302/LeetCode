#include <vector>
#include <algorithm>

class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        // Sort the points based on x-coordinates
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        int maxWidth = 0;
        // Iterate through sorted points and calculate the width
        for (int i = 1; i < points.size(); ++i) {
            int width = points[i][0] - points[i - 1][0];
            maxWidth = std::max(maxWidth, width);
        }

        return maxWidth;
    }
};
