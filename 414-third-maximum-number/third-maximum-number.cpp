class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;

        for(int n : nums) {
            if(n == first || n == second || n == third) continue;

            if(n > first) {
                third = second;
                second = first;
                first = n;
            }
            else if(n > second) {
                third = second;
                second = n;
            }
            else if(n > third) {
                third = n;
            }
        }

        return third == LLONG_MIN ? first : third;
    }
};
