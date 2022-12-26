//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = Integer.parseInt(sc.next());
		while(t-- > 0)
		{
		    int n = Integer.parseInt(sc.next());
		    int k = Integer.parseInt(sc.next());
		    
		    String[] words = new String[n];
		    
		    for(int i=0;i<n;i++)
		    {
		        words[i] = sc.next();
		    }
		    
		    Solution ob = new Solution();
		  //  System.out.println(T.findOrder(words,k));
		    String order = ob.findOrder(words,n,k);
		    if(order.length() == 0){
		        System.out.println(0);
		        continue;
		    }
		    String temp[] = new String[n];
		    for(int i=0;i<n;i++)
		        temp[i] = words[i];
		    
		    Arrays.sort(temp, new Comparator<String>(){
		    
		      @Override
                public int compare(String a, String b) {
                    int index1 = 0;
                    int index2 = 0;
                    for(int i = 0; i < Math.min(a.length(), b.length()) 
                                        && index1 == index2; i++) {
                        index1 = order.indexOf(a.charAt(i));
                        index2 = order.indexOf(b.charAt(i));
                    }
                
                    if(index1 == index2 && a.length() != b.length()) 
                    {
                        if(a.length() < b.length())
                            return -1;
                        else
                            return 1;
                    }
                
                    if(index1 < index2)
                        return -1;
                    else
                        return 1;
                        
                }
		    });
		    
		    int flag = 1;
		    for(int i=0;i<n;i++)
		    {
		        if(!words[i].equals(temp[i]))
	            {
	                flag = 0;
	                break;
	            }
		    }
		    
		    System.out.println(flag);
		}
	}
	
}

// } Driver Code Ends


//User function Template for Java

class Graph
{
    List<List<Integer>> adj = new ArrayList<>();
    
    Graph(int n)
    {
        for(int i=0;i<n;i++)
        {
            adj.add(i,new ArrayList<Integer>());
        }
    }
        
    void addEdge(int from, int to) 
    { 
        adj.get(from).add(to); 
    }
    
    int getNoOfVertices() 
    { 
        return adj.size(); 
    } 
    
    void topologicalSortUtil(int curr, boolean[] visited, Stack<Integer> st) 
    { 
        visited[curr] = true; 
  
        for (int i= 0;i< adj.get(curr).size();i++) 
        { 
            int x = adj.get(curr).get(i);
            if(!visited[x]) 
            { 
                topologicalSortUtil(x, visited, st); 
            } 
        } 
  
        st.push(curr); 
    } 
  
    public String topologicalSort() 
    { 
        Stack<Integer> st = new Stack<>(); 
        int n = getNoOfVertices();
        boolean[] visited = new boolean[n]; 
        for(int i = 0;i < n;i++) 
            visited[i] = false; 
  
        for(int i = 0;i < n;i++)
            if (!visited[i]) 
               topologicalSortUtil(i, visited, st);
        
        String ans = "";
        while (!st.isEmpty())
            ans += (char)('a' + st.pop()); 
        
        adj.clear(); 
        return ans;
 
    } 
    
}


class Solution
{
    public String findOrder(String [] words, int n, int k)
    {
        Graph g = new Graph(k);
        // int n = words.length;
        for (int i = 0; i < n - 1; i++) 
        { 
            int len = Math.min(words[i].length(), words[i+1].length());
            for(int j = 0;j < len;j++) 
            { 
                if(words[i].charAt(j) != words[i+1].charAt(j)) 
                { 
                    g.addEdge(words[i].charAt(j) - 'a', words[i+1].charAt(j)- 'a'); 
                    break; 
                } 
            } 
        } 
  
        String ans = g.topologicalSort();
        return ans;
    }
}