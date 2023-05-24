class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int,int>> vt;
    for(int i=0;i<nums2.size();i++)
    {
        vt.push_back({nums2[i],nums1[i]});
    }    
    sort(vt.begin(),vt.end());
    reverse(vt.begin(),vt.end());
    long long sum=0;
    priority_queue<int , vector<int> , greater<int>>pq;
    for(int i=0;i<k-1;i++)
    {
        sum+=vt[i].second;
        pq.push(vt[i].second);
    }
    long long ans=0;
    for(int i=k-1;i<nums2.size();i++)
    {
        sum+=vt[i].second;
        pq.push(vt[i].second);
        ans=max(ans,sum*vt[i].first);
        sum-=pq.top();
        pq.pop();
    }
    return ans;
    }
};