from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid) + 1
        m = len(grid[0]) + 1
        dp = [[float('inf')] * m for _ in range(n)]

        
        for i in range(n):
            for j in range(m):
                if i == 1 and j == 1:
                    dp[1][1] = grid[0][0]
                else:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i - 1][j - 1])
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i - 1][j - 1])

        return dp[n - 1][m - 1]
