dp = [0] * 50
class Solution:
    def climbStairs(self, n: int) -> int:
        if dp[n] != 0:
            return dp[n]

        res = 0
        if n == 1:
            res = 1
        elif n == 2:
            res = 2
        else:
            res = self.climbStairs(n-1) + self.climbStairs(n-2)
        dp[n] = res
        return res

