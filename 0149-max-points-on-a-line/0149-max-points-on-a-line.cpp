/*
line is determined by slope and offset

y = ax + b

but we actually don't need to use a double map of map[a][b] = set(pts) to record
the unique points on the line.

As we are doing an exhaustive O(n^2) search anyway. Say we are consider

points[0] (call it as pivot pt) with points[1] to points[n - 1]

for any points that is on the same line with points[0], it must be discovered
when we do this loop.

So such line can't have more points in the later search. E.g. when we use other
point as pivot, it just can't give a larger count on the same line. So
conceptually we have a map[line] -> set(pts on the line), and the line passes
the pivot point, then we must be able to find the max count on this line.

Also because we now are checking lines that will pass the pivot point at each
iteration, we don't need to care about the offset.

So map[line] is basically okay to simplify as map[slope]
So we no longer need the map[slope][offset] to characterize map[line]
*/

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    const int n = points.size();
    int maxCnt = 0;
    for (int i = 0; i < n; ++i) {
      const auto& pivotPt = points[i];
      std::unordered_map<double, int> slopeCnt;
      int infSlopeCnt = 0;
      for (int j = i + 1; j < n; ++j) {
        const auto& checkPt = points[j];
        if (pivotPt[0] == checkPt[0]) {
          maxCnt = std::max(maxCnt, ++infSlopeCnt);
        } else {
          const auto slope =
              double(checkPt[1] - pivotPt[1]) / (checkPt[0] - pivotPt[0]);
          maxCnt = std::max(maxCnt, ++slopeCnt[slope]);
        }
      }
    }
    // +1 because in each loop, we are not adding the pivotPt into the cnt
    // so the actual answer must be +1 of what we've gathered
    return maxCnt + 1;
  }
};