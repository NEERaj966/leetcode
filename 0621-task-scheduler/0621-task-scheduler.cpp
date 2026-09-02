class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        unordered_map<char, int> re;

        int seat = 1;

        for (char val : tasks) {
            freq[val]++;
            re[val] = 1;
        }

        // {frequency, task}
        priority_queue<pair<int, char>> pq;

        for (auto val : freq) {
            pq.push({val.second, val.first});
        }

        while (!pq.empty()) {
            vector<pair<int, char>> pulled;

            while (!pq.empty()) {
                auto [fre, child] = pq.top();
                pq.pop();

                if (re[child] <= seat) {

                    if (fre > 1) {
                        pq.push({fre - 1, child});
                        re[child] = seat + n + 1;
                    }

                    break;
                }
                else {
                    pulled.push_back({fre, child});
                }
            }

            for (auto x : pulled) {
                pq.push(x);
            }

            seat++;
        }

        return seat - 1;
    }
};