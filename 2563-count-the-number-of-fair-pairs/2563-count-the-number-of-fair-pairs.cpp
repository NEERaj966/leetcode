class Solution {
public:
    long long countPairs(vector<int>& nums, long long limit) {
        int left = 0;
        int right = nums.size() - 1;
        long long count = 0;

        while (left < right) {
            long long sum = (long long)nums[left] + nums[right];

            if (sum <= limit) {
                count += right - left;
                left++;
            } else {
                right--;
            }
        }

        return count;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return countPairs(nums, upper)
             - countPairs(nums, (long long)lower - 1);
    }
};