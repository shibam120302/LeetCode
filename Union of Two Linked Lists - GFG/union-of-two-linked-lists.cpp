//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int> myset;                 // this set will store all elements
        // elements appearing more than once get stored only once in set
        set<int>::iterator it;
        
        while(head1)
        {
            myset.insert(head1->data);  // inserting all elements in a set
            head1=head1->next;
        }
        
        while(head2)
        {
            myset.insert(head2->data);  // inserting all elements in a set
            head2 = head2->next;
        }
        
        it=myset.begin();               // it points to first element of set
        struct Node* union_head = new Node(*it);   // head of union list
        struct Node* union_tail = union_head;      // tail of union list
        
        for( ++it  ;  it!=myset.end()  ;  it++ )
        {
            union_tail->next = new Node(*it);      // adding all elements
            union_tail = union_tail->next;
        }
        
        return union_head;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends