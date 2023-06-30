class Solution {
public:
    
string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }

    string prev = countAndSay(n - 1);
    string result;

    int count = 1;
    char digit = prev[0];

    for (int i = 1; i < prev.length(); i++) {
        if (prev[i] == digit) {
            count++;
        } else {
            result += to_string(count) + digit;
            count = 1;
            digit = prev[i];
        }
    }

    result += to_string(count) + digit;
    return result;
}
    
};