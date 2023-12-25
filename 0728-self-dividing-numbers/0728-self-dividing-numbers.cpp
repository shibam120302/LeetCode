class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>arr;
        for(int i=left;i<=right;i++){
            int x=i;
            int rem;
            int flag=0;
            while(x!=0){
                rem=x%10;
                if(rem==0){
                    flag=1;
                    break;
                }
                if(i%rem!=0){
                    flag=1;
                    break;
                }
                x/=10;
            }
            if(flag==0){
                arr.push_back(i);
            }
        }
        return arr;
    }
};