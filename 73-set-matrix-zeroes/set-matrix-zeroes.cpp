class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> b = matrix;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {

                    for(int t = 0; t < m; t++) b[t][j] = 0;
                    for(int p = 0; p < n; p++) b[i][p] = 0;
                }
            }
        }

        // Copy back 
        matrix = b;
    }
};
