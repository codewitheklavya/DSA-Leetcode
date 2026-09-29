class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;

        while(low<=high){
            int mid = low+(high-low)/2;

            //target found
            if(nums[mid]==target) return true;

            //duplicate found
            if(nums[mid] == nums[low]) low++;

            //left half is sorted
            else if(nums[mid]>nums[low]){
                if(nums[mid]>=target && nums[low]<=target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[high]>=target){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};