from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mi = prices[0]
        ans = 0
        for i in prices:
            mi = min(mi, i)
            ans = max(ans, i - mi)
        return ans