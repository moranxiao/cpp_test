class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(i == 0)
                    {
                        dp[i+1][j+1] = dp[i+1][j] + grid[i][j];
                    }
                    else if(j == 0) dp[i+1][j+1] = dp[i][j+1] + grid[i][j];
                    else  dp[i+1][j+1] = min(dp[i][j+1],dp[i+1][j]) + grid[i][j];
                }
            }
            return dp[n][m];
        }
    };