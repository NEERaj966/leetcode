class Solution {
public:
    void visitNode(int i, int j, vector<vector<int>>& grid,
                   vector<vector<bool>>& vis, int m, int n , int& curr) {

        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            grid[i][j] == 0) {
            return;
        }

        vis[i][j] = true;
        curr++;

        // Right
        visitNode(i, j + 1, grid, vis, m, n , curr);

        // Left
        visitNode(i, j - 1, grid, vis, m, n , curr);

        // Down
        visitNode(i + 1, j, grid, vis, m, n , curr);

        // Up
        visitNode(i - 1, j, grid, vis, m, n , curr);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int curr = 0;
                    visitNode(i, j, grid, vis, m, n , curr);
                    maxarea = max(maxarea , curr);
                    
                }
            }
        }
        return maxarea;
    }
};