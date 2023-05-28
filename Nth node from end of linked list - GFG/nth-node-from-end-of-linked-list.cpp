//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
int getNthFromLast(struct Node *head, int n)
{
    //using two pointers, similar to finding middle element.
    struct Node *currNode = head , *nthNode = head;
    
    //traversing first n elements with first pointer.
    while(n!=0)
        {
            if(currNode==NULL)
                return -1;
            currNode = currNode->next;
            n--;
        }
    //now traversing with both pointers and when first pointer gives null 
    //we have got the nth node from end in second pointer since the first 
    //pointer had already traversed n nodes and thus had difference of n 
    //nodes with second pointer.
    while(currNode!=NULL)   
        {
            nthNode = nthNode->next;
            currNode = currNode->next;
        }
    
    //returning the data of nth node from end.
    if(nthNode!=NULL)
        return nthNode->data;
    else
        return -1;
        
}