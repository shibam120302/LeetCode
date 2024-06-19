class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 0 , e = 1e9;
        int mid = s+(e-s)/2 , ans = -1;
        while(s<=e){
            int con = 0 , buk = 0;
            for(int i=0;i<bloomDay.size();i++){
                // if the day comes within mid day
                if(bloomDay[i]<=mid){
                    con++;
                    // if it is a continuous day , check if a bouquet can be made
                    if(con>=k){
                    buk++;
                    con = 0;
                    }
                }
                else con = 0;
            }

            //if got required bouquets , store the day and search on left
            if(buk>=m){
                ans = mid;
                e = mid-1;
            }
            //otherwise search on right
            else s = mid+1;
            //update mid
            mid = s+(e-s)/2;
        }
        return ans;
    }
};