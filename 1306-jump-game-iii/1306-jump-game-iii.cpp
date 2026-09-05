
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int index = q.front();
            q.pop();

            if (arr[index] == 0)
                return true;

            int right = index + arr[index];
            int left = index - arr[index];

            if (right < n && !visited[right]) {
                visited[right] = true;
                q.push(right);
            }

            if (left >= 0 && !visited[left]) {
                visited[left] = true;
                q.push(left);
            }
        }

        return false;
    }
};

