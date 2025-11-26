class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, current, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& current, vector<vector<int>>& result) {
        
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates: if same number and previous duplicate not used
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            if (!used[i]) {
                used[i] = true;
                current.push_back(nums[i]);

                backtrack(nums, used, current, result);

                current.pop_back();
                used[i] = false;
            }
        }
    }
};
