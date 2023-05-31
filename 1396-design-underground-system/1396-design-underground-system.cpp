class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkinTime;
    map<pair<string, string>, vector<int>> travelTimes;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        checkinTime.insert({id, {stationName, t}});
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkin = checkinTime[id];
        auto departStation = checkin.first;
        auto departTime = checkin.second;
        auto travelTime =  t - departTime;
        travelTimes[{departStation, stationName}].push_back(travelTime);
        checkinTime.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int n = travelTimes[{startStation, endStation}].size();
        double total = 0;
        for (auto time : travelTimes[{startStation, endStation}]) {
            total += time;
        }
        return total / n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */