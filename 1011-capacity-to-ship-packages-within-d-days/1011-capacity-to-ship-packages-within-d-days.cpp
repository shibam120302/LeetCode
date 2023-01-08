class Solution {
public:
int fnc(int mid,vector<int>& weights, int days) {
       int count = 1, sum = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                count++;
                sum = weights[i];
            }
        }
        if (count <= days){return true;}
            
        return false;

return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int max=0;
        int ans;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
        }
        int low = *max_element(weights.begin(), weights.end());int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(fnc(mid,weights,days)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};