class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long m = (long long) mid;
            if(m*m==x) return m;
            else if(m*m>x) high = m-1;
            else low = m+1;
        }
        return high;
    }
};