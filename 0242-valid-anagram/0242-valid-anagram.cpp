class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> ans(26, 0);

        for (char val : s) {
            ans[val - 'a']++;
        }

        for (char val : t) {
            ans[val - 'a']--;
        }

        for (int count : ans) {
            if (count != 0)
                return false;
        }

        return true;
    }
};