//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.io.*;

public class Main
{
    public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    String inputLine[] = br.readLine().trim().split(" ");
		    int n = Integer.parseInt(inputLine[0]);
		    int m = Integer.parseInt(inputLine[1]);
		    long arr1[] = new long[n];
		    long arr2[] = new long[m];
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<n; i++){
		        arr1[i] = Long.parseLong(inputLine[i]);
		    }
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<m; i++){
		        arr2[i] = Long.parseLong(inputLine[i]);
		    }
		    Solution ob = new Solution();
		    ob.merge(arr1, arr2, n, m);
		    
		    StringBuffer str = new StringBuffer();
		    for(int i=0; i<n; i++){
		        str.append(arr1[i]+" ");
		    }
		    for(int i=0; i<m; i++){
		        str.append(arr2[i]+" ");
		    }
		    System.out.println(str);
		}
	}
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    //Function to find next gap.
    public static int nextGap(int gap) {
        
        //It returns the ceil value of gap/2 or 0 if gap is 1.
        if(gap <= 1) return 0; 
        return (gap / 2) + (gap % 2); 
    }
    
    //Function to merge the arrays.
    public static void merge(long arr1[], long arr2[], int n, int m) {
        int i, j, gap = n + m;
        long tmp;
        
        for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
            
            //Comparing elements in the first array itself with difference in 
    	    //index equal to the value of gap.
            for(i = 0; i + gap < n; i++){
                if(arr1[i] > arr1[i + gap]){
                    
                    //If element at ith index is greater than element at
    		        //(i+gap)th index, we swap them.
                    tmp = arr1[i];
                    arr1[i] = arr1[i + gap];
                    arr1[i+gap] = tmp;
                }
            }
            
            //Now comparing elements in both arrays with help of two pointers.
    		//The loop stops whenever any pointer exceeds the size of its array
            for(j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++){
                
                //If element in the first array is greater than element in
    		    //second array, we swap them.
                if(arr1[i] > arr2[j]){
                    tmp = arr1[i];
                    arr1[i] = arr2[j];
                    arr2[j] = tmp;
                }
            }
            
            if(j < m) {
                //At last, comparing elements in the second array itself with 
                //difference in index equal to the value of gap.
                for (j = 0; j + gap < m; j++){
                    
                    //If element at jth index is greater than element at
    		        //(j+gap)th index, we swap them.
                    if(arr2[j] > arr2[j + gap]){
                        tmp = arr2[j];
                        arr2[j] = arr2[j + gap];
                        arr2[j + gap] = tmp;
                    }
                }
            }
        }
    }
}