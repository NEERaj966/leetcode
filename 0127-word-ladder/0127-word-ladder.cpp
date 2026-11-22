
class Solution {
public:
    int ladderLength(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> st(
            wordList.begin(),
            wordList.end()
        );

        // Destination must exist
        if (st.find(endWord) == st.end())
            return 0;

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while (!q.empty()) {

            auto [word, level] = q.front();
            q.pop();

            // Change each character
            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    // Check if generated word exists
                    if (st.find(word) != st.end()) {

                        // Destination reached
                        if (word == endWord)
                            return level + 1;

                        q.push({word, level + 1});

                        // Mark visited
                        st.erase(word);
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};
