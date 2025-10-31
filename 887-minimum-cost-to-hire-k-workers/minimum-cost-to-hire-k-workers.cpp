class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        // Step 1: Build vector of (ratio, quality)
        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        // Step 2: Sort by ratio
        sort(workers.begin(), workers.end());

        vector<int> qualities;
        qualities.reserve(k);
        double totalQuality = 0.0;
        double minCost = DBL_MAX;

        for (int i = 0; i < n; i++) {
            // insert in sorted order (so we can remove largest efficiently)
            auto pos = lower_bound(qualities.begin(), qualities.end(), workers[i].second);
            qualities.insert(pos, workers[i].second);
            totalQuality += workers[i].second;

            // remove largest if > k
            if ((int)qualities.size() > k) {
                totalQuality -= qualities.back();
                qualities.pop_back();
            }

            // compute min cost when we have exactly k
            if ((int)qualities.size() == k) {
                minCost = min(minCost, totalQuality * workers[i].first);
            }
        }

        return minCost;
    }
};
