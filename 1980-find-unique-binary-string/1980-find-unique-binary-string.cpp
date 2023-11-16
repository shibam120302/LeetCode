class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int len=nums[0].size();
        vector<bool> hasX(1<<len, 0);

        #pragma unroll 
        for(auto& x:  nums)
            hasX[bitset<16>(x).to_ulong()]=1;
        int N=0;//find N

        #pragma unroll
        for(; N<(1<<len) && hasX[N]; N++);
    //    cout<<N<<endl;
        return bitset<16>(N).to_string().substr(16-len,len);
    }
};