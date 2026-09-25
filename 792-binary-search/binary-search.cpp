class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int hi = nums.size()-1;
        while(low<=hi){
            int mid = low+(hi-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                low = mid+1;
            }
            else if(nums[mid]>target){
                hi = mid-1;
            }
        }
        return -1;
    }
};