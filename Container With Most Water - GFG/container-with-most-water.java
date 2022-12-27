//{ Driver Code Starts
//Initial Template for Java


import java.io.*;
import java.util.*;
import java.lang.*;


class GFG {
	public static void main (String[] args) throws IOException{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    int n = Integer.parseInt(br.readLine()); // input size of array
		    int arr[] = new int[n];
		    String inputLine[] = br.readLine().trim().split("\\s+");
		    for(int i=0; i<n; i++){
		        arr[i] = Integer.parseInt(inputLine[i]); // input elements of array
		    }
		    Solve T = new Solve();
            long ans = T.maxArea(arr,n);
            System.out.println(ans);
		}
	}
}

// } Driver Code Ends


//User function Template for Java


class Solve{
    
    long maxArea(int A[], int len){
        int l = 0;      // left wall of container
    	int r = len -1; // right wall of container
    	long area = 0;
    
    	while (l < r)
    	{
    		// Calculating the max area
    		area = Math.max(area, Math.min(A[l], A[r]) * (r - l));
    
            // maximise height of container
    		if (A[l] < A[r])
    			l += 1;
    		else
    			r -= 1;
    	}
    	return area;
    }
    
}