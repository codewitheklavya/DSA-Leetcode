class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size()-1;
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<n-i;j++){
                if(nums[j]==0){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        return;
    }
};