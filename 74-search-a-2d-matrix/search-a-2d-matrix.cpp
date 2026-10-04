class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int hi = n*m-1;

        while(low<=hi){
            int mid = low+(hi-low)/2;

            if(matrix[mid/n][mid%n] == target) return true;
            else if(matrix[mid/n][mid%n] > target) hi = mid-1;
            else low = mid+1;
        }
        return false;
    }
};