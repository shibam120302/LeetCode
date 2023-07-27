//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    void swap(int *a,int *b)
    {
    	int c=*a;
    	*a=*b;
    	*b=c;
    }
    
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int l=i*2+1;
    	int r=i*2+2;
    	int largest=i;
    	
    	//if left or right child is greater than current element, 
        //we store its position.
    	if(l<n && arr[largest]<arr[l])
    		largest=l;
    	if(r<n && arr[largest]<arr[r])
    		largest=r;
    	
    	//if largest is not equal to i, we swap the values at their position.	
    	if(largest!=i)
    	{
    		swap(&arr[i],&arr[largest]);
    		//calling function recursively for the largest variable.
    		heapify(arr,n,largest); 
    	}
    }
    
    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n) 
    { 
        //calling heapify function for values from half to first index.
    	for(int i=n/2-1;i>=0;i--)
    	   heapify(arr,n,i); 
    }
    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //calling function to build heap with array.
        buildHeap(arr, n);
        for (int i=n-1; i>=0; i--)
        {
            //swapping values at current and first index.
            swap(&arr[0], &arr[i]);
            //calling heapify function for first index.
            heapify(arr, i, 0);
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends