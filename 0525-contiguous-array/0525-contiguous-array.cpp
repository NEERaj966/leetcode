class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        int ans = 0;
        int sum = 0;

        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                sum--;
            else
                sum++;

            if (mp.find(sum) != mp.end()) {
                int curr = i - mp[sum];
                ans = max(ans, curr);
            }
            else {
                mp[sum] = i;
            }
        }

        return ans;
    }
};