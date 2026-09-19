class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int left = 1;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            int count = 0;

            for (int num : nums) {
                if (num <= mid)
                    count++;
            }

            if (count > mid) {
                // Duplicate is in the left half
                right = mid;
            }
            else {
                // Duplicate is in the right half
                left = mid + 1;
            }
        }

        return left;
    }
};