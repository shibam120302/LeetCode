class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int col = A[0].size(), i = 0, num = A.size(), j = 0;
        vector<int> ans;
        bool flag = 0;
        for(j = 0; j < col; j++){
            flag = 1;
            for(i = 0; i < num-1; i++){
                if(A[i][j] > A[i+1][j]){
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                ans.push_back(j);
            }
            
        }
        return ans.size();
        
        
    }
};