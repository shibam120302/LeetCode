class Solution {
public:
    //returns true if "word1" is smaller or equal to "word2"
    bool wordCompare(vector<int>&mp, string& word1, string& word2) 
    {
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size())
        {
            int pos1 = mp[word1[i] - 'a'];
            int pos2 = mp[word2[j] - 'a'];
            if (pos1 < pos2) return true;
            else if (pos2 < pos1) return false;  //if pos1 == pos2, keep comparing

            i++; 
            j++;   
        }
        //control will come here only if the characters compared are equal
        //so smaller length word will be smaller in lex order
        return (word1.size() <= word2.size());
    }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        vector<int>mp(26);
        for (int i = 0; i < order.size(); i++) mp[order[i] - 'a'] = i; 
        //mapped characters to their pos in (new alphabet)
        
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!wordCompare(mp, words[i], words[i + 1])) 
                return false;
        }
        return true;
        
    }
};