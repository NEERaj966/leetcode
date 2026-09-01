
class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {

        int st = 0;
        int end = nums.size() - 1;

        int firstocc = -1;
        int lastocc = -1;

        // Find first occurrence
        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                firstocc = mid;
                end = mid - 1;       // Go left
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        // Find last occurrence
        st = 0;
        end = nums.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                lastocc = mid;
                st = mid + 1;        // Go right
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return {firstocc, lastocc};
    }
};

