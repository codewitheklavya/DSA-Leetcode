class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        // Prune: check character frequency
        vector<int> freq(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int f : freq)
            if (f != 0)
                return memo[key] = false;

        int n = s1.size();
        for (int i = 1; i < n; i++) {
            // Case 1: no swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return memo[key] = true;

            // Case 2: swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }
};
