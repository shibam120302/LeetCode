class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        for(int i=0;i<arr.size()-2;i++){
            if(arr[i]<arr[i+1] && arr[i+1]>arr[i+2]) //Simply using the condition given
            return i+1;
        }
        return 0;
    }
};