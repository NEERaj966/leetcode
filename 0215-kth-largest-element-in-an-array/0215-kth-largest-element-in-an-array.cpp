class Solution {
public:
    int quickselect(vector<int>& nums, int st, int end) {

        int pivot = nums[end];

        int i = st;

        while (i < end) {

            if (pivot > nums[i]) {
                swap(nums[st], nums[i]);
                st++;
            }

            i++;
        }

        // Put pivot at its correct position
        swap(nums[st], nums[end]);

        return st;
    }

    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        int st = 0;
        int end = n - 1;

        int target = n - k;

        while (st <= end) {

            int pivotidx = quickselect(nums, st, end);

            if (pivotidx == target) {
                return nums[pivotidx];
            }

            if (pivotidx < target) {
                st = pivotidx + 1;
            }
            else {
                end = pivotidx - 1;
            }
        }

            return -1;
    }
};