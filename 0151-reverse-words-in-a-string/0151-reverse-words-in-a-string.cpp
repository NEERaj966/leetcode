
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n - 1;
        string ans = "";

        while (i >= 0) {
            // Skip spaces
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            if (i < 0) break;

            int j = i;

            // Find the beginning of the word
            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            // Add a space between words
            if (!ans.empty()) {
                ans += ' ';
            }

            // Append the word
            ans += s.substr(i + 1, j - i);
        }

        return ans;
    }
};
