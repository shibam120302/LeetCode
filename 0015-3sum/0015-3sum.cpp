class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        
        vector< vector<int> > result;
    if(num.size() == 0 || num.size() == 1 || num.size() == 2) return result;

    //sort the array, this is the key
    sort(num.begin(), num.end());

    int n = num.size();

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i > 0 && num[i - 1] == num[i]) continue;
        int a = num[i];
        int low = i + 1;
        int high = n - 1;
        while (low < high) {
            int b = num[low];
            int c = num[high];
            if (a + b + c == 0) {
                //got the soultion
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                // Continue search for all triplet combinations summing to zero.
                //skip the duplication
                while(low < n - 1 && num[low] == num[low + 1]) low++; 
                while(high > 0 && num[high] == num[high - 1]) high--; 
                low++;
                high--;
            } else if (a+b+c > 0) {
                //skip the duplication
                while(high > 0 && num[high] == num[high - 1]) high--;
                high--;
            } else {
                //skip the duplication
                while(low < n - 1 && num[low] == num[low + 1]) low++;
                low++;
            } 
        }
    }
    return result;
}
        
    
};