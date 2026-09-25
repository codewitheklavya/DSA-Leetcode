class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        //first occurrence
        int low = 0;
        int hi = nums.size()-1;
        int first = -1;
        while(low<=hi){
            int mid = low+(hi-low)/2;
            if(nums[mid]==target){
                first = mid;
                hi = mid-1;
            }else if(nums[mid]<target){
                low = mid + 1;
            }else{
                hi = mid -1;
            }
        }

        //Last occr
        low = 0;
        hi = nums.size()-1;
        int last = -1;

        while(low<=hi){
            int mid = low + (hi-low)/2;
            if(nums[mid]==target){
                last = mid;
                low = mid + 1;
            }else if(nums[mid]<target){
                low = mid + 1;
            }else{
                hi = mid-1;
            }
        }

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};