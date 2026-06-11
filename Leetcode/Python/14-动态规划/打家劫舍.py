from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        pre1 = 0
        pre2 = 0
        for num in nums:
            current = max(pre1, pre2 + num)
            pre2 = pre1
            pre1 = current
        return pre1

