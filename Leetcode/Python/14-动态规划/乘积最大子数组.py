from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curr_max = nums[0]
        curr_min = nums[0]
        global_max = nums[0]
        for i in range(1, len(nums)):
            num = nums[i]
            pre_max = curr_max
            pre_min = curr_min

            curr_max = max(num, pre_max * num, pre_min * num)
            curr_min = min(num, pre_max * num, pre_min * num)

            global_max = max(global_max, curr_max)
        return global_max


