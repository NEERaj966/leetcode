class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = n - 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                n--;
            }
        }

        int i = 0;

        while (k >= i) {
            if (nums[i] == val && nums[k] == val)
                k--;

            else if (nums[i] == val && nums[k] != val) {
                swap(nums[i], nums[k]);
                i++;
            }else i++;
        }

        return n;
    }
};