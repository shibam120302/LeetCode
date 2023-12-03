class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int k=0;
        for(int i=1;i<points.size();i++)
        k+=std::max(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
        return k;
    }
};