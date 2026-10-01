class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;

        int left = 0;
        int right = arr.size() - 1;

        // Case 1: x is greater than all elements
        if (x > arr[right]) {
            for (int i = right; i > right - k; i--) {
                v.push_back(arr[i]);
            }

            sort(v.begin(), v.end());
            return v;
        }

        // Case 2: x is smaller than all elements
        if (x < arr[left]) {
            for (int i = left; i < left + k; i++) {
                v.push_back(arr[i]);
            }

            return v;
        }

        int lb = 0;
        int ub = 0;

        // Find the position around x
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == x) {
                v.push_back(arr[mid]);
                lb = mid - 1;
                ub = mid + 1;
                break;
            }
            else if (arr[mid] < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // x was not found
        if (lb == 0 && ub == 0) {
            ub = left;
            lb = left - 1;
        }

        // Pick k closest elements
        while (v.size() < k) {

            // Left side finished
            if (lb < 0) {
                v.push_back(arr[ub]);
                ub++;
            }

            // Right side finished
            else if (ub >= arr.size()) {
                v.push_back(arr[lb]);
                lb--;
            }

            // Both sides available
            else {
                int lsum = abs(arr[lb] - x);
                int upsum = abs(arr[ub] - x);

                if (lsum <= upsum) {
                    v.push_back(arr[lb]);
                    lb--;
                }
                else {
                    v.push_back(arr[ub]);
                    ub++;
                }
            }
        }

        sort(v.begin(), v.end());

        return v;
    }
};