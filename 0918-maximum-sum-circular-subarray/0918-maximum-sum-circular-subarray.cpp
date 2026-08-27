class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        int currMax = 0;
        int currMin = 0;

        int totalSum = 0;

        for (int x : nums) {
            // Maximum subarray Kadane
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            // Minimum subarray Kadane
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);

            totalSum += x;
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};