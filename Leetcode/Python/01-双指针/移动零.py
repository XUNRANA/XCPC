from typing import List
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = 0
        j = 0
        while i < n:
            if nums[i] != 0:
                t = nums[i]
                nums[i] = nums[j]
                nums[j] = t
                j += 1
            i += 1
        print(nums)

"""
0 1 0 3 12
"""        


if __name__ == "__main__":
    nums = list(map(int, input().split()))
    s = Solution()
    s.moveZeroes(nums)
