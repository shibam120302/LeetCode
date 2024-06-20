class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // force is bound between the min and maximum value of the position of the positions array
        // find minimum distance that is maxmimized across others
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0;
        int r = 1e9;


        int curMax = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (isValid(mid, position) >= m) { // can check higher days
                l = mid + 1;
                curMax = max(curMax, mid);
            } else { // check lower days
                r = mid - 1;
            }
        }
        return curMax;
    }
    
    int isValid(int mid, vector<int> position) {
            int total = 1;
            int curDist = position[0];
            for (int i = 1; i < position.size(); i++) {
                if (position[i] - curDist >= mid) {
                    total++;
                    curDist = position[i];
                }
            }
            return total;
        }
};