/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int maxPosition = -1;
        int left = 1;
        int right = n - 2;
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        maxPosition = left;
        left = 0;
        right = maxPosition;
        int me;

        while (left <= right) {
            mid = left + (right - left) / 2;
            me = mountainArr.get(mid);

            if (me == target) return mid;
            if (me > target) right = mid - 1;
            else left = mid + 1;
        }
        left = maxPosition;
        right = n - 1;

        while (left <= right) {
            mid = left + (right - left) / 2;
            me = mountainArr.get(mid);

            if (me == target) return mid;
            if (me < target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
