
from typing import Optional

class Solution:
    def isPrime(self,n):
        nn = int(n**0.5) + 1
        for i in range(2 , nn):
            if n%i == 0:return False
        return True
            
            
    def primeList(self, head : Optional['Node']) -> Optional['Node']:
        temp = head
        while temp:
            
            if temp.data == 1:
                temp.data = 2
            else:
                num = temp.data
                num1 = temp.data
                num2 = temp.data
                while not self.isPrime(num1): num1-=1
                while not self.isPrime(num2): num2+=1
                
                if num - num1 <= num2 - num:
                    temp.data = num1
                else:
                    temp.data = num2
            temp = temp.next
        return head
        

#{ 
 # Driver Code Starts
class Node:
    def __init__(self,x):
        self.data=x
        self.next=None

def printList(node):
    while (node != None):
        print(node.data,end=" ")
        node = node.next
    print()
def inputList():
    n=int(input())#lenght of link list
    data=[int(i) for i in input().strip().split()]#all data of linked list in a line
    head = Node(data[0])
    tail = head;
    for i in range(1,n):
        tail.next = Node(data[i]);
        tail = tail.next;
    return head;

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        head = inputList()
        
        obj = Solution()
        res = obj.primeList(head)
        
        printList(res)
        

# } Driver Code Ends