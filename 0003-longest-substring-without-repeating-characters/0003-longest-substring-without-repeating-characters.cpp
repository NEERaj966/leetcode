class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1);

        int st = 0;
        int ans = 0;

        for (int end = 0; end < s.size(); end++) {

            if (index[s[end]] != -1) {
                st = max(st, index[s[end]] + 1);
            }

            int currlen = end - st + 1;
            ans = max(ans, currlen);

            index[s[end]] = end;
        }

        return ans;
    }
};