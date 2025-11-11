class Solution {
public:
    bool canForm(string &word, unordered_set<string> &dict) {
        int n = word.size();
        if (n == 0) return false;

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j]) continue;
                string sub = word.substr(j, i - j);
                if (dict.count(sub)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> result;

        for (auto &word : words) {
            dict.erase(word);  // temporarily remove current word
            if (canForm(word, dict)) {
                result.push_back(word);
            }
            dict.insert(word); // add it back
        }

        return result;
    }
};
