class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        int rem = k%n;
        //reverse entire array
        reverse(nums.begin(),nums.end());
        
        //reverse first k elem
        reverse(nums.begin(),nums.begin()+rem);

        //reverse remaining elem
        reverse(nums.begin()+rem,nums.end());
        
        return;
    }
};