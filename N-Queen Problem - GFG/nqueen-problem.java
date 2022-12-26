//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.lang.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0) {
            int n = Integer.parseInt(in.readLine());
            
            Solution ob = new Solution();
            ArrayList<ArrayList<Integer>> ans = ob.nQueen(n);
            if(ans.size() == 0)
                System.out.println("-1");
            else {
                for(int i = 0;i < ans.size();i++){
                    System.out.print("[");
                    for(int j = 0;j < ans.get(i).size();j++)
                        System.out.print(ans.get(i).get(j) + " ");
                    System.out.print("] ");
                }
                System.out.println();
            }
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution{
    
    static ArrayList<ArrayList<Integer>> result;
    static int[] row = new int[10];
    static int k = 0;
    
    static boolean place(int r,int c) {
    	for(int prev=0;prev<c;prev++)
    		if(row[prev]==r ||(int)Math.abs(row[prev]-r) == (int)Math.abs(prev-c))
    			return false;
    	return true;
    }
    
    static void bt(int c,int n) {
    	if(n == 2 || n == 3) 
    	    return;
    	if(c == n) {
    		
    		ArrayList<Integer> v = new ArrayList<Integer>();
    		
    		for(int i = 0;i < n;i++)
    		    v.add(row[i]+1);
    		result.add(v);
    		k++;
    	}
    	
    	for(int i = 0;i < n;i++) {
    		if(place(i, c)) {
    			row[c] = i;
    			bt(c+1, n);
    		}
    	}
    }
    
     static ArrayList<ArrayList<Integer>> nQueen(int n) {
        result = new ArrayList<ArrayList<Integer>>();
        bt(0, n);
        return result;
    }
}