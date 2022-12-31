//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {

            int i = 0;
            int N = Integer.parseInt(br.readLine().trim());

            int start[] = new int[N];
            int end[] = new int[N];

            String inputLine2[] = br.readLine().trim().split(" ");
            String inputLine3[] = br.readLine().trim().split(" ");
            
            for (i = 0; i < N; i++) {
                start[i] = Integer.parseInt(inputLine2[i]);
                end[i] = Integer.parseInt(inputLine3[i]);
            }
            
            Solution ob = new Solution();
            System.out.println(ob.minLaptops(N, start, end));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    public int minLaptops(int n, int[] start, int[] end) {
        // code here
        int[][] arr=new int[n][2];
        for(int i=0;i<n;i++){
            arr[i]=new int[]{start[i],end[i]};
        }

        Arrays.sort(arr,(a,b)->{
            if(a[0]!=b[0])return a[0]-b[0];
            return a[1]-b[1];
        });

        int ans=1;
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        pq.add(arr[0][1]);
        int i=1;
        while(i<n){
            int s=arr[i][0];
            int e=arr[i][1];
            if(pq.peek()<=s){
                pq.remove();
            }else{
                ans++;
            }
            pq.add(e);
            i++;
        }
        return ans;
    }
}
