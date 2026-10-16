
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];
            int k = i + 1;
            int j = n - 1;

            while (k < j) {
                int temp = nums[k] + nums[j];

                if (temp == target) {
                    ans.push_back({nums[i], nums[k], nums[j]});

                    k++;
                    j--;

                    // Skip duplicate second elements
                    while (k < j && nums[k] == nums[k - 1]) {
                        k++;
                    }

                    // Skip duplicate third elements
                    while (k < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
                }
                else if (temp < target) {
                    k++;
                }
                else {
                    j--;
                }
            }
        }

        return ans;
    }
};
