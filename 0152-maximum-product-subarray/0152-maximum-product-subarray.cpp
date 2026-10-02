class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0]; // to track max product
        int mini = nums[0]; // to track negative max 
        int ans = nums[0];  // to track max 

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < 0)
                swap(maxi, mini);

            maxi = max(nums[i], maxi * nums[i]);
            mini = min(nums[i], mini * nums[i]);

            ans = max(ans, maxi);
        }

        return ans;
    }
};