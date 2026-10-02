class Solution {
public:
    bool ispossible(vector<int>&nums , int n , int k , int maxval){
        int part = 1; 
        int val = 0;

        for(int i = 0 ; i < n ; i++){
            
            if(val+nums[i] <= maxval){
                val = val+nums[i];
            }else{
                val = nums[i];
                part++;
            }
        }

        return part <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxel = INT_MIN;
        int sum = 0;
        int ans = 0;

        for(int val : nums){
            sum += val;

            maxel = max(maxel , val);
        }

        int st = maxel , end = sum;

        while(st <= end){
            int mid = st+(end-st)/2;

            if(ispossible(nums , n , k , mid)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
};