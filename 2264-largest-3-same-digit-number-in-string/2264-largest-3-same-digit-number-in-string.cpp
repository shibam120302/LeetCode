class Solution
{
    public:
        string largestGoodInteger(string num)
        {

            string temp = "";
            string str;
            char c = num[0];
            str.push_back(c);
            for (int i = 1; i < num.length(); i++)
            {
                if (num[i] == c) str.push_back(num[i]);
                else
                {
                    c = num[i];
                    str = "";
                    i--;
                }
                if (str.length() == 3 && str > temp) temp = str;
            }
            return temp;
        }
};