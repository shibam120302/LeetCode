class Solution {
public:
    bool winnerOfGame(string colors) {
        int l = colors.length();
        int ca=0, cb=0;
        if(l<3) return false;
        for(int i=0; i<=l-3; ++i){
            if(colors[i]==colors[i+1] && colors[i+1]==colors[i+2]){
                if(colors[i] == 'A') ca++;
                else cb++;
            }
        }
        return ca>cb;
    }
};