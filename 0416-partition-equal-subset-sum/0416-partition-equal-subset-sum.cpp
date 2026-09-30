class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for (int x : nums) {
            total += x;
        }

        // If total is odd, equal partition is impossible
        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;

        // dp[i][j] = can we make sum j using first i elements?
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Sum 0 is always possible
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= target; j++) {

                // Don't take nums[i-1]
                dp[i][j] = dp[i - 1][j];

                // Take nums[i-1]
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i][j] ||
                               dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};