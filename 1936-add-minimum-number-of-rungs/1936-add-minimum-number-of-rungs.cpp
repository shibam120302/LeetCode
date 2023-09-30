class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        int c=0;
        int p=0;
        for (int i = 0; i <n ; i ++){
            c+= (rungs[i]-p-1)/dist;
            p=rungs[i];
            
        }
        return c;
    }
};