class Solution {
public:
    bool isPalindrome(string s) {
        // Create a new string to hold the filtered and lowercased characters
        string filtered;
        
        // Filter the string to only include alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        
        // Check if the filtered string is a palindrome
        int left = 0;
        int right = filtered.size() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false; // Characters do not match, not a palindrome
            }
            left++;
            right--;
        }
        
        return true; // All characters match, it is a palindrome
    }
};