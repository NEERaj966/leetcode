class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // Put smaller index in minIdx and larger index in maxIdx
        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        // Option 1: remove both from the left
        int left = maxIdx + 1;

        // Option 2: remove both from the right
        int right = n - minIdx;

        // Option 3: remove minIdx from left and maxIdx from right
        int both = (minIdx + 1) + (n - maxIdx);

        return min({left, right, both});
    }
};