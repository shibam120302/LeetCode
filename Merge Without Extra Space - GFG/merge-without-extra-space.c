//{ Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


// } Driver Code Ends
//User function Template for C

//Function to find next gap.
int nextGap(int gap) 
{ 
    //It returns the ceil value of gap/2 or 0 if gap is 1.
	if (gap <= 1) 
		return 0; 
	return (gap / 2) + (gap % 2); 
} 
    
//Function to merge the arrays.
void merge(int arr1[], int arr2[], int n, int m)
{ 
	int i, j, gap = n + m; 
	
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
	{ 
	    //Comparing elements in the first array itself with difference in 
	    //index equal to the value of gap. 
		for (i = 0; i + gap < n; i++) {
		    //If element at ith index is greater than element at
		    //(i+gap)th index, we swap them. 
			if (arr1[i] > arr1[i + gap]){
			    int temp = arr1[i];
				arr1[i] = arr1[i + gap];
				arr1[i + gap] = temp;
			} 
		}
    
		//Now comparing elements in both arrays with help of two pointers.
		//The loop stops whenever any pointer exceeds the size of its array.
		for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) {
		    //If element in the first array is greater than element in
		    //second array, we swap them. 
			if (arr1[i] > arr2[j]){
			    int temp = arr1[i];
				arr1[i] = arr2[j];
				arr2[j] = temp;
			} 
		}
        
		if (j < m) 
		{ 
			//At last, comparing elements in the second array itself with 
            //difference in index equal to the value of gap.
			for (j = 0; j + gap < m; j++) {
			    //If element at jth index is greater than element at
		        //(j+gap)th index, we swap them. 
				if (arr2[j] > arr2[j + gap]){
				    int temp = arr2[j];
				    arr2[j] = arr2[j + gap];
				    arr2[j + gap] = temp;
				} 
			}
		} 
	} 
}

//{ Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n,m;
		scanf("%d", &n);
		scanf("%d", &m);
		int *arr1;
		arr1 = (int*)malloc(n * sizeof(int));
		for(int i=0;i<n;i++)
    		scanf("%d", &arr1[i]);
		int *arr2;
		arr2 = (int*)malloc(m * sizeof(int));
		for(int i=0;i<m;i++)
    		scanf("%d", &arr2[i]);
    	
    	merge(arr1,arr2,n,m);
    	for(int i=0;i<n;i++)
    		printf("%d ", arr1[i]);
		for(int i=0;i<m;i++)
    		printf("%d ", arr2[i]);
    	printf("\n");
	}
	return 0;
}
// } Driver Code Ends