class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
      int sum = 0, n = colors.length() , j = 0,  max_time = neededTime[0];
      char prev = colors[0];
      while(j<n){
           while(j<n and colors[j] == prev){
                 max_time = max(max_time , neededTime[j]);
                 j++;
           }
           if(j>=n) {sum += max_time; break;}
           prev = colors[j];
           sum += max_time;
           max_time = neededTime[j];
      }    
      int total_time = accumulate(neededTime.begin() , neededTime.end(),0);
      return total_time-sum;
    }
};