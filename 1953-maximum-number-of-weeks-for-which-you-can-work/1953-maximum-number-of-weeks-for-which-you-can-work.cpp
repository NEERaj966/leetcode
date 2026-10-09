
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        long long mx = 0;

        for (int val : milestones) {
            sum += val;
            mx = max(mx, (long long)val);
        }

        long long remaining = sum - mx;

        return min(sum, 2 * remaining + 1);
    }
};

// class Solution {
// public:
//     long long numberOfWeeks(vector<int>& milestones) {
//         priority_queue<pair<int, int>> pq;

//         int i = 0;
//         for (int val : milestones) {
//             if (val > 0) {
//                 pq.push({val, i});
//             }
//             i++;
//         }

//         long long weeks = 0;
//         int lastProject = -1;
//         pair<int, int> previous = {-1, -1};

//         while (!pq.empty()) {
//             auto [freq, project] = pq.top();
//             pq.pop();

//             // Cannot work on the same project consecutively.
//             if (project == lastProject) {
//                 if (pq.empty()) break;

//                 auto [freq2, project2] = pq.top();
//                 pq.pop();

//                 weeks++;
//                 lastProject = project2;
//                 freq2--;

//                 if (freq2 > 0) {
//                     pq.push({freq2, project2});
//                 }

//                 pq.push({freq, project});
//             } else {
//                 weeks++;
//                 lastProject = project;
//                 freq--;

//                 if (freq > 0) {
//                     pq.push({freq, project});
//                 }
//             }
//         }

//         return weeks;
//     }
// };
