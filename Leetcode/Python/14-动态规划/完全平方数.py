class Solution:
    def numSquares(self, n: int) -> int:
        squares = [ x * x for x in range(1, int(n ** 0.5) + 1)]
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for s in squares:
                if i < s:
                    break
                dp[i] = min(dp[i], dp[i - s] + 1)
        return dp[n]
        
        


