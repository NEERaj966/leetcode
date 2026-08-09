
class Solution {
public:
    void visitNode(int i, int j, vector<vector<char>>& grid,
                   vector<vector<bool>>& vis, int m, int n) {

        if (i < 0 || j < 0 || i >= n || j >= m ||
            vis[i][j] || grid[i][j] == '0') {
            return;
        }

        vis[i][j] = true;

        // Right
        visitNode(i, j + 1, grid, vis, m, n);

        // Left
        visitNode(i, j - 1, grid, vis, m, n);

        // Down
        visitNode(i + 1, j, grid, vis, m, n);

        // Up
        visitNode(i - 1, j, grid, vis, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int island = 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {
                    visitNode(i, j, grid, vis, m, n);
                    island++;
                }
            }
        }

        return island;
    }
};

