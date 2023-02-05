class Solution {
public:
bool check(int arr[26],int brr[26]){
    for(int i=0;i<26;i++){
        if(arr[i]!=brr[i]) return false;
    }
    return true;
}
    vector<int> findAnagrams(string &s, string &p) {
        int count1[27]={0};
        vector<int>ans;
        for(int i=0;i<p.size();i++) count1[p[i]-'a']++;
        int i=0,j=0,n=s.size(),m=p.size();
        int count2[27]={0};
        while(i<n&&j<m){
            count2[s[i]-'a']++;
            i++;
            j++;
        }
        j=0;    
        bool a=check(count1,count2);
        if(a) ans.push_back(0);
        while(i<n){
            count2[s[i]-'a']++;
            count2[s[j]-'a']--;
            if(check(count1,count2) )ans.push_back(j+1);
            i++,j++;
        }
return ans;
    }
};