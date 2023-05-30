class Solution:
    
    def isWordExist(self, board, word):
        
        for i in range(len(board)):
            for j in range(len(board[0])):
        
                if board[i][j] == word[0] and self.adjacentSearch(board, word, i, j, 0):
                    return True
                    
        return False
    
    def adjacentSearch(self, board, word, i, j, length):
        
        if length == len(word):
            return True
            
        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]):
            return False
            
        if board[i][j] != word[length]:
            return False
            
        board[i][j] = '*'  # Mark the cell as visited
        ans = self.adjacentSearch(board, word, i - 1, j, length + 1) or \
              self.adjacentSearch(board, word, i + 1, j, length + 1) or \
              self.adjacentSearch(board, word, i, j - 1, length + 1) or \
              self.adjacentSearch(board, word, i, j + 1, length + 1)
              
        board[i][j] = word[length]  # Restore the cell's original value
        return ans
#{ 
 # Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for tt in range(T):
		n, m = map(int, input().split())
		board = []
		for i in range(n):
			a = list(input().strip().split())
			b = []
			for j in range(m):
				b.append(a[j][0])
			board.append(b)
		word = input().strip()
		obj = Solution()
		ans = obj.isWordExist(board, word)
		if(ans):
			print("1")
		else:
			print("0")

# } Driver Code Ends