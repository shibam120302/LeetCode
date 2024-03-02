class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> freqBucket(10000 + 1);
       
        for(auto num : nums){
            if(num < 0){
                freqBucket[num * -1]++;
            }else freqBucket[num]++;
        }
        vector<int> res;
       
        for(int num = 0; num < freqBucket.size(); num++){
            if(freqBucket[num] > 0){
               int numFreq = freqBucket[num]; 
               while(numFreq-->0) 
                res.push_back(num * num);
            }
        }
        return res;
    }
};