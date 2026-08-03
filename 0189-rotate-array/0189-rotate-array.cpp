class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;              // Handle k > n
        int d = n - k;

        reverse(nums.begin(), nums.begin() + d);
        reverse(nums.begin() + d, nums.end());
        reverse(nums.begin(), nums.end());
    }
};