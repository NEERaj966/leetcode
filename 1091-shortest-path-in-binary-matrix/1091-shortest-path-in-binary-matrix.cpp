
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Check starting and ending cells
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // 8 directions
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        queue<tuple<int,int,int>> q;

        // {row, col, distance}
        q.push({0, 0, 1});

        // Mark visited
        grid[0][0] = 1;

        while (!q.empty()) {

            auto [row, col, dist] = q.front();
            q.pop();

            // Destination reached
            if (row == n-1 && col == n-1)
                return dist;

            // Explore 8 directions
            for (int i = 0; i < 8; i++) {

                int nr = row + dx[i];
                int nc = col + dy[i];

                // Check boundaries and availability
                if (nr >= 0 && nc >= 0 &&
                    nr < n && nc < n &&
                    grid[nr][nc] == 0) {

                    grid[nr][nc] = 1; // Visited

                    q.push({nr, nc, dist + 1});
                }
            }
        }

        return -1;
    }
};
