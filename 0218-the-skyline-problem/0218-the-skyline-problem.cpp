class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> events;
        events.reserve(buildings.size() * 2);
        
        for (const auto& b : buildings) {
            const auto l = b.front(), r = b[1], h = b.back();
            events.emplace_back(l, -h);
            events.emplace_back(r, h);
        }
        sort(events.begin(), events.end());
        
        vector<vector<int>> res;
        multiset<int> heights;
        heights.emplace(0);
        
        int max_height_so_far = 0;
        for (const auto& [c, h] : events) {
            if (h < 0) {
                heights.insert(-h);
            } else {
                heights.erase(heights.find(h));
            }
            
            const int curr_height = *(heights.rbegin());
            if (curr_height != max_height_so_far) {
                res.emplace_back(vector<int>{c, curr_height});
                max_height_so_far = curr_height;
            }
        }
        return res;
    }
};
