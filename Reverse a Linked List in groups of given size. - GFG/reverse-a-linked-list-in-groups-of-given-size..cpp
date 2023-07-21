//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    pair<struct node *,struct node *> helperReverse(struct node  *head,int k)
    {
        struct node  *prev=NULL,*curr=head,*next=NULL;
        while(curr && k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            k--;
        }
        return {prev,curr};
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node  *prev=NULL;
        struct node  *ans;
        int f=1;
        int c=0;
        while(head)
        {
            c++;
            pair<struct node *,struct node *> t=helperReverse(head,k);
            if(f)
                ans=t.first;
            f=0;
            if(prev)
                prev->next=t.first;
            prev=head;
            head=t.second;
        }
        return ans;
    }
};

//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends