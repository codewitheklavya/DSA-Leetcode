class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size()-1;
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i = i+2){
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[n];
    }
};