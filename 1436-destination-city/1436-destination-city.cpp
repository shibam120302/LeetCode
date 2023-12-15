class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> p;
        for(auto& e:paths){
            string& v0=e[0], v1=e[1];
            p[v0]=-1;//not destination
            if(p.count(v1)==0) 
                p[v1]=1;//possible destination
        }
        for (auto& [v, c]:p)
            if (c==1) return move(v);//only 1 destination
        return NULL;
    }
};