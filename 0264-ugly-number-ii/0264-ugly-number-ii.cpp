class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)    return 1;

        vector<int> vec;
        vec.push_back(1);
        int p2=0 , p3=0 , p5=0 , ugly=1 , count=1 ;
        
        while(count < n)
        {
            ugly = min( { 2*vec[p2] , 3*vec[p3] , 5*vec[p5] } ) ;
            vec.push_back(ugly) ;
            count++;
            
            if(ugly%2 == 0)    p2++;
            if(ugly%3 == 0)    p3++;
            if(ugly%5 == 0)    p5++;
        }
        return ugly;
    }
};