class Solution {
public:
    static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int prev=0;
        int res=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[prev][1]>intervals[i][0])
                res++;
            else{
                prev=i;
            }
        }
        return res;
    }
};