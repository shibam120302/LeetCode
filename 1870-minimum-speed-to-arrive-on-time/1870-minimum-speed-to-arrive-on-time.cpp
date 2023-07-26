class Solution {
public:
    int n;
    double time(vector<int>& dist, int speed){
        double sum=0;
        for(int i=0; i<n-1; i++)
            sum+=(dist[i]+speed-1)/speed;//ceiling function
        sum+=(double)dist[n-1]/speed;// last one just normal division
    //    cout<<"speed="<<speed<<",time="<<sum<<endl;
        return sum;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        n=dist.size();
       
        if (hour<=n-1) return -1;
        long long left=1;
        int right=1e9;// Constraint
        int speed;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if (time(dist, mid)<=hour){
                speed=mid;
                right=mid-1;
            } 
            else left=mid+1;
        }
        return speed;
    }
};