class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int k = 0;

        while (j < nums.size()) {
            if (j == 0 || nums[j] != nums[j - 1]) {
                k = 1;
            } else {
                k++;
            }

            if (k <= 2) {
                nums[i] = nums[j];
                i++;
            }

            j++;
        }

        return i;
    }
};