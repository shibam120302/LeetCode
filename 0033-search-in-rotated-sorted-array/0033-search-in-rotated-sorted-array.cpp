class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0, high=arr.size()-1, mid=0;
        while(low <= high){
            mid = low+(high-low)/2;
            if(arr[mid] == target)
                return mid;
            //  Either this part is sorted in accending order
            if(arr[low] <= arr[mid]){
                //  If arr[low] <= target <= arr[high], search in th left part
                if(target >= arr[low] and target <= arr[mid])
                    high = mid-1;
                //  Otherwise neglect left part
                else
                    low = mid+1;
            }
            //  Or this part is sorted in accending order
            else{
                //  If arr[low] <= target <= arr[high], search in this part
                if(target >= arr[mid] and target <= arr[high])
                    low = mid+1;
                //  Otherwise neglect this part
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};