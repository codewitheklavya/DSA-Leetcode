class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int hi = nums.size()-1;
        int mid = (low+hi)/2;
        while(low<=hi){
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                low = mid+1;
                mid = (low+hi)/2;
            }
            else if(nums[mid]>target){
                hi = mid-1;
                mid = (low+hi)/2;
            }
        }
        return -1;
    }
};