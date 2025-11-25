class Solution {
public:
    vector<string> result;

    void backtrack(int open, int close, int n, string current) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have left parentheses to use
        if (open < n) {
            backtrack(open + 1, close, n, current + "(");
        }

        // Add ')' only if it doesn't break the validity
        if (close < open) {
            backtrack(open, close + 1, n, current + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n, "");
        return result;
    }
};
