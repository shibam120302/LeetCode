class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int check;
    KthLargest(int k, vector<int>& nums) {
        check=k;
        for(auto i:nums)
        {
            q.push(i);
            if(q.size()>check)
                q.pop();
        }
    }

    int add(int val) {
        q.push(val);
        if(q.size()>check)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */