from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        c0 = nums.count(0)
        res = []
        if c0 == 0:
            ans = 1
            for num in nums:
                ans *= num
            for num in nums:
                res.append(ans//num)
        elif c0 == 1:
            for num in nums:
                if num == 0:
                    ans = 1
                    for num in nums:
                        if num != 0:
                            ans *= num
                    res.append(ans)
                else:
                    res.append(0)
        else:
            for num in nums:
                res.append(0)    
        return res

        