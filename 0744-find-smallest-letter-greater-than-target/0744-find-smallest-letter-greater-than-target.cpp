class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        int s=0;
        int e=l.size()-1;
        char ans=target;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(l[mid]>target){
                ans=l[mid];
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        if(ans==target) return l[0];
        return ans;
    }
};