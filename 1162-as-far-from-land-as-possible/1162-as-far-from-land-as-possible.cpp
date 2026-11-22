
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair<int,int>> q;

        // Step 1: Insert all land cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // All land or all water
        if(q.empty() || q.size() == n * n)
            return -1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int dist = -1;

        // Step 2: Multi-source BFS
        while(!q.empty()) {

            int sz = q.size();

            dist++;

            // Process current level
            while(sz--) {

                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {

                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    // Check boundaries and water
                    if(nx >= 0 && ny >= 0 &&
                       nx < n && ny < n &&
                       grid[nx][ny] == 0) {

                        grid[nx][ny] = 1; // Visited

                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};
