class Solution {
public:
    int helper(vector<string>& words, vector<int>& score, int idx, vector<int>& freq){
        if(idx==words.size()) return 0;
        int sc1=helper(words,score,idx+1,freq);

        bool pos=true;
        int sc=0;
        for(auto c:words[idx]){
            freq[c-'a']--;
            sc+=score[c-'a'];
            if(freq[c-'a']<0) pos=false;
        }

        if(pos){
            int sc2=helper(words,score,idx+1,freq);
            for(auto c:words[idx]) freq[c-'a']++;
            return max(sc1,sc2+sc);
        }
        else{
            for(auto c:words[idx]) freq[c-'a']++;
            return sc1;
        }
    }

    int maxScoreWords(vector<string> words, vector<char> letters, vector<int> score) {
        vector<int> freq(26,0);
        for(auto l:letters) freq[l-'a']++;
        return helper(words, score, 0, freq);
    }
};