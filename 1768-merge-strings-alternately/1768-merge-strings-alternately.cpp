class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str = "" ; 
        int n = word1.length() ;
        int m = word2.length() ; 
        int num ;
        if (n > m )
        {
            num = n ;
        }
        else num = m ; 

        for (int i = 0 ; i < num ; i++)
        {
            if (i < n)
            {
                str += word1[i] ;
            }
            if (i < m )
            {
                str += word2[i] ;
            }
        }
        return str ; 
    }
};