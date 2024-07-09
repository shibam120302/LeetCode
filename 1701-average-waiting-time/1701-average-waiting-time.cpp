class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        const int n=customers.size();
        double prepare=0, sum=0;
        for(auto& t: customers){
            prepare=((t[0]>prepare)?t[0]:prepare)+t[1];
            sum+=prepare-t[0];
        }
        return sum/n;
    }
};