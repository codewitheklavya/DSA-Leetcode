class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        //finding pivot index
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot==-1){//if Array if already Greatest
            reverse(nums.begin(),nums.end());
            return;
        }
        //sorting/reverse after pivot
        reverse(nums.begin()+pivot+1,nums.end());

        //finding the just greater element than pivot 
        int j = -1;
        for(int i=pivot+1;i<n;i++){
            if(nums[i]>nums[pivot]){
                j = i;
                break;
            }
        }

        //now swaping
        int temp = nums[pivot];
        nums[pivot] = nums[j];
        nums[j] = temp;
        return;
    }
};