class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=right.empty()?0:n-*min_element(right.begin(), right.end());
        int r=left.empty()?0:*max_element(left.begin(), left.end());
        return max(l, r);
    }
};