class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            int m = grid.size();
            int n = grid[0].size();

            if (m == 0)
                return 0;
            if (m == 1 && n == 1)
                return grid[0][0];

            vector<vector<int> > min_path(grid);
            min_path[0][0] = grid[0][0];

            for (int i = 1; i < n; i++) {
                min_path[0][i] = min_path[0][i-1] + grid[0][i];
            }

            for (int i = 1; i < m; i++) {
                min_path[i][0] = min_path[i-1][0] + grid[i][0];
            }

            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    int left = min_path[i][j-1];
                    int up = min_path[i-1][j];

                    min_path[i][j] = left < up ? left + grid[i][j] : up + grid[i][j];
                }
            }

            return min_path[m-1][n-1];
        }
};
