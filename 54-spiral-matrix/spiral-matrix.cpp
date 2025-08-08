class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minr = 0; int minc = 0;
        int maxr = m-1; int maxc = n-1;
        vector<int> v;
        while(minr<=maxr && minc<=maxc){
            //right
            for(int i=minc;i<=maxc;i++){
                v.push_back(matrix[minr][i]);
            }
            minr++;
            if(minr>maxr || minc>maxc) break;
            //down
            for(int j=minr;j<=maxr;j++){
                v.push_back(matrix[j][maxc]);
            }
            maxc--;
            //left
            if(minr>maxr || minc>maxc) break;
            for(int i=maxc;i>=minc;i--){
                v.push_back(matrix[maxr][i]);
            }
            maxr--;
            //up
            if(minr>maxr || minc>maxc) break;
            for(int j=maxr;j>=minr;j--){
                v.push_back(matrix[j][minc]);
            }
            minc++;
        }
        return v;
    }
};