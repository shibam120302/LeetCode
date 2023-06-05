class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {       
        int n=coordinates.size();
        double x0=coordinates[0][0], y0=coordinates[0][1];
        bool isVertical=(coordinates[1][0]==x0);
        double slope=(coordinates[1][1]-y0)/(coordinates[1][0]-x0); 
        cout<<"slope="<<slope<<endl; 
        for(int i=2; i<n; i++){
            if (isVertical){
                if (coordinates[i][0]!=x0)  return 0;
                continue;
            } 
            else if ((coordinates[i][1]-y0)!=(coordinates[i][0]-x0)*slope) 
                return 0;
        }
        return 1;
    }
};