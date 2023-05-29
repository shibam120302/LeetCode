#User function Template for python3

import sys
sys.setrecursionlimit(10**6)
# Alphabet size (# of upper-Case characters)
ALPHABET_SIZE = 26
class TrieNode:
    def __init__(self):
        # Array to store child nodes
        self.children = [None] * ALPHABET_SIZE
        # Flag to indicate if the node represents the end of a word
        self.isLeaf = False
        # List to store complete words in leaf node
        self.word = []
# Returns a new Trie node (initialized to None values)
def getNewTrieNode():
    pNode = TrieNode()
    if pNode:
        pNode.isLeaf = False
        for i in range(ALPHABET_SIZE):
            pNode.children[i] = None
    return pNode
class Solution:
    # Function to insert a word into the Trie
    def insert(self, root, word):
        pCrawl = root
        for level in range(len(word)):
            # Consider only uppercase characters
            if word[level].islower():
                continue
            # Get the current character position
            index = ord(word[level]) - ord('A')
            if not pCrawl.children[index]:
                pCrawl.children[index] = getNewTrieNode()
            pCrawl = pCrawl.children[index]
        # Mark the last node as leaf
        pCrawl.isLeaf = True
        # Append the word to the list associated with the leaf node
        pCrawl.word.append(word)
    # Function to print all words stored in the Trie
    def printAllWords(self, root):
        # If current node is a leaf node
        if root.isLeaf:
            for word in root.word:
                self.ans.append(word)
        # Recurse for all children of the root node
        for child in root.children:
            if child:
                self.printAllWords(child)
    # Search for a pattern in the Trie and print all words matching that pattern
    def search(self, root, pattern):
        pCrawl = root
        for level in range(len(pattern)):
            index = ord(pattern[level]) - ord('A')
            # Invalid pattern
            if not pCrawl.children[index]:
                return
            pCrawl = pCrawl.children[index]
        # Print all words matching the pattern
        self.printAllWords(pCrawl)
    # Main function to print all words in the CamelCase dictionary that match a given pattern
    def CamelCase(self, N, Dict, pattern):
        # List to store all matching words
        self.ans = []
        # Construct Trie root node
        root = getNewTrieNode()
        # Construct Trie from given dictionary
        for word in Dict:
            self.insert(root, word)
        # Search for the pattern in the Trie
        self.search(root, pattern)
        if len(self.ans)==0:
            self.ans.append("-1")
        return self.ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        Dictionary=list(map(str,input().split()))
        Pattern=input()
        ob=Solution()
        ans=ob.CamelCase(N,Dictionary,Pattern)
        ans.sort()
        for i in ans:
            print(i,end=" ")
        print()    
# } Driver Code Ends