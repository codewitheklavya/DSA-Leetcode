class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long rev = 0;
        long long dup = x;
        int lastd = 0;
        while(x>0){
            lastd = x % 10;
            x = x/10;
            rev = (rev*10)+lastd;
        }
        if(rev==dup) return true;
        else return false;
    }
};