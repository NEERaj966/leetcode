class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        int count = 1;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (lastEnd <= intervals[i][0]) {
                // Keep this interval
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};