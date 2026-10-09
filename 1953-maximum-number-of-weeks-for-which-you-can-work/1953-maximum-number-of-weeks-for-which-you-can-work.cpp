
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