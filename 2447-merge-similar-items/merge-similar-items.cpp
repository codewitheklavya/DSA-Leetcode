class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;

        // Merge items from items1
        for (auto &v : items1) {
            mp[v[0]] += v[1];
        }

        // Merge items from items2
        for (auto &v : items2) {
            mp[v[0]] += v[1];
        }

        // Convert map to answer format
        vector<vector<int>> ans;
        for (auto &p : mp) {
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};
