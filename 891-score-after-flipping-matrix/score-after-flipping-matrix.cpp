class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //making 1st cols all 1
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){//flip
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        //flip the cols where nums of zeros are greater than nums of ones
        for(int j=0;j<n;j++){
            int noz = 0;
            int noo = 0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==0) noz++;
                else noo++;
            }
            if(noz>noo){//flip
                for(int i=0;i<m;i++){
                    if(grid[i][j]==0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        int sum = 0;
        for(int i=0;i<m;i++){
            int x = 1;
            for(int j=n-1;j>=0;j--){
                sum +=grid[i][j]*x;
                x*=2;
            }
        }
        return sum;
    }
};