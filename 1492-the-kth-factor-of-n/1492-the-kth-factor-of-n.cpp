class Solution {
public:
    int kthFactor(int n, int k) {
      long long int i;
      int ans=0;
      vector<int>y;
          for(i=1;i<=n;i++){
              if(n%i==0){
           y.push_back(i);}
           }
      
    if(y.size()<k){
        return -1;
    }
  return y[k-1];   }
};