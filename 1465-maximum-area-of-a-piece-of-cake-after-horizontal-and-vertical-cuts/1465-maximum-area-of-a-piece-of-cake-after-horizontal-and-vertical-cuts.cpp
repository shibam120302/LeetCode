class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        sort(hCuts.begin(),hCuts.end());
        sort(vCuts.begin(),vCuts.end());
    int maxiW=hCuts[0];
    for(int i=1;i<hCuts.size();i++){
        maxiW=max(maxiW,hCuts[i]-hCuts[i-1]);
    }
    maxiW=max(maxiW,abs(h-hCuts[hCuts.size()-1]));

      
    int maxiH=vCuts[0];
    for(int i=1;i<vCuts.size();i++){
        maxiH=max(maxiH,vCuts[i]-vCuts[i-1]);
    }
    maxiH=max(maxiH,abs(w-vCuts[vCuts.size()-1]));
   

    return (long(maxiH)*long(maxiW))%1000000007;
    }
};