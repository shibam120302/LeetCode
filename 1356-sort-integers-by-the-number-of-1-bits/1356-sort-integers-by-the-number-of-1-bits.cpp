class Solution {
  private:
  static int helper(int num){
    int cnt = 0;
    for(int i=0; i<32; i++){
        if(num>>i&1) cnt++;
    }
    return cnt;
}

static bool customCmp(int & a, int &b){
    if(helper(a)==helper(b)) return a<=b;
    return helper(a)<helper(b);
}
public:

    vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin() , arr.end() , customCmp);
    // for(auto ele : arr) cout<<ele<<" ";  
    return arr;
}
};