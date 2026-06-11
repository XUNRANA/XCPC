from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        pre_sum = 0
        mp = {0: 1}
        for num in nums:
            pre_sum += num
            target = pre_sum - k
            if target in mp:
                count += mp[target]
            mp[pre_sum] = mp.get(pre_sum, 0) + 1
        return count

