class Solution {
public:
    int sumSq(int n) {
        int s = 0;
        while (n > 0) {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = sumSq(slow);         // move 1 step
            fast = sumSq(sumSq(fast));  // move 2 steps
        } while (slow != fast);

        return slow == 1;
    }
};
