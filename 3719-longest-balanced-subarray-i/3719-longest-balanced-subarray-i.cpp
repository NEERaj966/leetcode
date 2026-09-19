class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int length = 0;

        for (int i = 0; i < nums.size(); i++) {
            int even = 0, odd = 0;
            unordered_map<int, int> mp;

            for (int j = i; j < nums.size(); j++) {
                if (mp.find(nums[j]) == mp.end()) {

                    if (nums[j] % 2 == 0)
                        even++;
                    else
                        odd++;

                    mp[nums[j]] = 1;
                }

                if (even == odd)
                    length = max(length, j - i);
            }
        }

        return length == 0 ? 0 : length + 1;
    }
};