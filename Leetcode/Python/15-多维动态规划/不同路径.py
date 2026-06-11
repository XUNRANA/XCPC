class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        n += 1
        m += 1
        dp = [[0] * n for _ in range(m)]

        
        for i in range(1, n):
            for j in range(1, m):
                if i == 1 and j == 1:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[m - 1][n - 1]

