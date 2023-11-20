class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
      unordered_map<int , vector<int>>mp;
      vector<int>last_index(3);
      for(int i=0; i<garbage.size(); i++){
        int m = 0 , p= 0, g =0;
        for(auto ch :garbage[i]){
          if(ch=='M')m++;
          else if(ch=='P')p++;
          else g++;
        }
        mp[i].push_back(m);  // 0th index for metal
        mp[i].push_back(p);  // 1st index for paper
        mp[i].push_back(g);  // 2nd index for glass
        if(m>0)last_index[0] = i;
        if(p>0)last_index[1] = i;
        if(g>0)last_index[2] = i;
      }

      // for metal
      int ans = 0;
      travel.insert(travel.begin(), 0);
      for(int i=0; i<=last_index[0]; i++){
          ans += mp[i][0];
          ans += travel[i];
      }
      // for paper
      for(int i=0; i<=last_index[1]; i++){
          ans += mp[i][1];
          ans += travel[i];
      }
      // for glass
      for(int i=0; i<=last_index[2]; i++){
          ans += mp[i][2];
          ans += travel[i];
      }

      return ans;


  }
};