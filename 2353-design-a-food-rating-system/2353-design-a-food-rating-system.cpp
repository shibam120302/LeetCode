struct comp{
    bool operator() (pair<int,string> &a,pair<int,string> &b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};

class FoodRatings {
public:
    
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>> mp;
    unordered_map<string,string> chk;
    unordered_map<string,int> rt;
    
    FoodRatings(vector<string>& foods, vector<string>& c, vector<int>& r) {
        for(int i=0;i<foods.size();i++){
            mp[c[i]].push({r[i],foods[i]});
            chk[foods[i]]=c[i];
            rt[foods[i]]=r[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        rt[food]=newRating;
        mp[chk[food]].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        string x = mp[cuisine].top().second;
        int y = mp[cuisine].top().first;
        while(rt[x]!=y){
            mp[cuisine].pop();
            x = mp[cuisine].top().second;
            y = mp[cuisine].top().first;
        }
        return mp[cuisine].top().second;
    }
};