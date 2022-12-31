class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int>q;
		int n=matrix.size();
		for(int i=0; i<n*n; i++){
			q.push(matrix[i/n][i%n]);
			if(q.size()>k){q.pop();}
		}
		return q.top();
	}
};