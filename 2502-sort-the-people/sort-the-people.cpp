class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        for (int i = 0; i < names.size(); i++) {
            v.push_back({heights[i], names[i]});
        }

        sort(v.rbegin(), v.rend()); // sort in descending order

        vector<string> ans;
        for (auto &p : v) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
