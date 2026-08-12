class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

       int  n = 0 , m = nums.size()-1;
        while(n <= m){
            int mid = n + (m-n)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(target < nums[0]){
                return 0;
            }
            if(target > nums[nums.size()-1]){
                return nums.size();
            }
            if(nums[mid] < target && nums[mid+1] > target){
                return mid+1;
            }
            
            if(nums[mid] < target){
                n = mid+1;
            }
            else{
                if(nums[mid] > target){
                    m = mid-1;
                }
            }
          
            
        }
            
        return 0;
        
    }
};