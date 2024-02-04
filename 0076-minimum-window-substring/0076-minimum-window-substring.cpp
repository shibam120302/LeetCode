class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int len1 = s.length();
        int len2 = t.length();
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;
        
        if(len1 < len2) {
            return "";
        }
        
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        //to keep track of all characters of P string
        for(auto x : t) {
            m2[x]++;
        }
        
        int count = 0;
        for(int i = 0; i < len1; i++) {
            char ch = s[i];
            
            m1[ch]++;
            
            //valid character -> jo character tumhare pattern me bhi ho 
            if(m1[ch] <= m2[ch]) {
                count++;
            }
            
            if(count == len2) {
                
                //window is ready
                
                //minimise the window -> freq decrement, ans update , start ko aage badhana h 
                char temp = s[start];
                while(m1[temp] > m2[temp] or m2[temp] == 0 ) {
                    
                    if(m1[temp] > m2[temp])
                        m1[temp]--;
                        
                    start++;
                    temp = s[start];
                }
                
                //ans update
                int lengthOfWindow = i - start + 1;
                if(lengthOfWindow < ansLen ) {
                    ansLen = lengthOfWindow;
                    ansIndex = start;
                }
                
                
            }
        }
        
        if(ansIndex == -1)
            return "";
        else
            return s.substr(ansIndex, ansLen);
    }
};