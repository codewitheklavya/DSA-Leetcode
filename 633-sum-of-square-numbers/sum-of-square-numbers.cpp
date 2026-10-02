class Solution {
public:

    bool isPerfectSqaure(int x){
        int root = sqrt(x);
        if(root * root == x) return true;
        else return false;
    }

    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        while(x<=y){
            if(isPerfectSqaure(x) && isPerfectSqaure(y)){
                return true;
            }else if(!isPerfectSqaure(x)){
                y = sqrt(y) * sqrt(y);
                x = c-y;
            }else{
                x = (sqrt(x)+1) * (sqrt(x)+1);
                y = c-x;
            }
        }
        return false;
    }
};