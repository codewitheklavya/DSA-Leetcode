class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // pointer for string s
        int j = 0; // pointer for string t
        
        // Iterate through both strings
        while (i < s.length() && j < t.length()) {
            // If characters match, move pointer for s
            if (s[i] == t[j]) {
                i++;
            }
            // Always move pointer for t
            j++;
        }
        
        // If we've matched all characters in s, return true
        return i == s.length();
    }
};