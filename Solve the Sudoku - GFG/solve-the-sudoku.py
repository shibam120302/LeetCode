#User function Template for python3

class Solution:
    
    #Function to print grids of the Sudoku.
    def printGrid(self,arr):
        for i in range(9):
            for j in range(9):
                print(arr[i][j], end=" ")

    
    #Function to return a boolean which indicates whether an assigned  
    #entry in the specified row matches the given number. 
    def used_in_row(self,arr,row,num):
        for i in range(9):
            if(arr[row][i] == num):
                return True
        return False
    
    
    #Function to return a boolean which indicates whether an assigned  
    #entry in the specified column matches the given number.
    def used_in_col(self,arr,col,num):
        for i in range(9):
            if(arr[i][col] == num):
                return True
        return False
    
    
    #Function to return a boolean which indicates whether an assigned
    #entry within the specified 3x3 box matches the given number.
    def used_in_box(self,arr,row,col,num):
        for i in range(3):
            for j in range(3):
                if(arr[i+row][j+col] == num):
                    return True
        return False
    
    
    #Function to return a boolean which indicates whether it will be 
    #legal to assign num to the given row, column location. 
    def check_location_is_safe(self,arr,row,col,num):
        return not self.used_in_row(arr,row,num) and not self.used_in_col(arr,col,num) and not self.used_in_box(arr,row - row%3,col - col%3,num)
    
    def find_empty_location(self,arr,l):
        for row in range(9):
            for col in range(9):
                if(arr[row][col]==0):
                    l[0]=row
                    l[1]=col
                    return True
        return False
    
    #Function to find a solved Sudoku. 
    def SolveSudoku(self,grid):
        
        l=[0,0]
    
        #if there is no unassigned location, we are done.
        if(not self.find_empty_location(grid,l)):
            return True
    
        row=l[0]
        col=l[1]
    
        #considering digits from 1 to 9  
        for num in range(1,10):
    
            if(self.check_location_is_safe(grid,row,col,num)):
    
                #making tentative assignment 
                grid[row][col]=num
                #if success, return true 
                if(self.SolveSudoku(grid)):
                    return True
                #failure, unmake & try again 
                grid[row][col] = 0
    
        #this triggers backtracking 
        return False




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t = int(input())
    while(t>0):
        grid = [[0 for i in range(9)] for j in range(9)]
        row = [int(x) for x in input().strip().split()]
        k = 0
        for i in range(9):
            for j in range(9):
                grid[i][j] = row[k]
                k+=1
                
        ob = Solution()
            
        if(ob.SolveSudoku(grid)==True):
            ob.printGrid(grid)
            print()
        else:
            print("No solution exists")
        t = t-1
# } Driver Code Ends