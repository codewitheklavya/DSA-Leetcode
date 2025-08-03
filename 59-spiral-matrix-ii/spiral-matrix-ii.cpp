class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};
        int m = n;  
        int minr = 0, minc = 0;
        int maxr = m - 1, maxc = n - 1;
        int count = 1;
        vector<vector<int>> matrix (m,vector<int>(n));

        while (minr <= maxr && minc <= maxc) {
            // right
            for (int j = minc; j <= maxc; j++) {
                matrix[minr][j] = count++;
            }
            minr++;
            if (minr > maxr || minc > maxc) break;

            // down
            for (int i = minr; i <= maxr; i++) {
                matrix[i][maxc] = count++;
            }
            maxc--;
            if (minr > maxr || minc > maxc) break;

            // left
            for (int j = maxc; j >= minc; j--) {
                matrix[maxr][j] = count++;
            }
            maxr--;
            if (minr > maxr || minc > maxc) break;

            // up
            for (int i = maxr; i >= minr; i--) {
                matrix[i][minc] = count++;
            }
            minc++;
        }
        return matrix;
    }
};