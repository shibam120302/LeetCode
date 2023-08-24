class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
		int k=maxWidth;
        string temp="";
        int n=words.size();
        
        vector<string> ans;
        
        int i=0;
        int currsize=0;
        int prev=0;
        
        while(i<n){
            
            
            
            int curr=words[i].size();
            i++;
            
            while(i<n and (curr+words[i].size()+1)<=k){
                curr+=(words[i].size()+1);
                i++;
            }
            
            string temp="";
            ans.push_back(temp);
            int m=i-prev;
            
            if(i==n or m==1){
                
                for(int j=prev;j<i;j++){
                    ans[currsize]+=words[j];
                    if(j!=(i-1)){
                        ans[currsize]+=' ';
                    }
                }
                
                int z=ans[currsize].size();
                while(z<k){
                    ans[currsize]+=' ';
                    z++;
                }
                
            }else{
                
                int gap=m-1;
                int left=k-curr;
                
                int a=left/gap;
                
                int x=(gap-(left%gap)) ; // gaps with 'a' no. of spaces
                int y=left%gap ; // gaps with 'a+1' no. of spaces
                
                
                for(int j=prev;j<i;j++){
                    
                    ans[currsize]+=words[j];
                    if(j!=(i-1)){
                        ans[currsize]+=' ';
                    }
                    
                    if(x>0 or y>0){
                        for(int t=0;t<a;t++){
                            ans[currsize]+=' ';
                        }
                    }
                    
                    if(y>0){
                        ans[currsize]+=' ';
                        y--;
                    }else{
                        x--;
                    }
                    
                }
            }
            
            currsize++;
            prev=i;
            
        }
        
        
        return(ans);
    }
};