class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n , vector<int>(m , 0));
        ans[0][0] = grid[0][0];

        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                if(i > 0 && j > 0 ){
                    ans[i][j] = min(ans[i-1][j] , ans[i][j-1])+ grid[i][j];
                }else if(i == 0 && j != 0){
                    ans[i][j] = ans[i][j-1]+grid[i][j];
                }else if(j == 0 && i != 0){
                    ans[i][j] = ans[i-1][j] + grid[i][j];
                }
            }
        }

        return ans[n-1][m-1];
    }
};