from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n <= 1:
            return
            
        # Step 1: 从后向前找“拐点” i
        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
            
        # 如果找到了拐点（说明不是纯降序的最后一个排列）
        if i >= 0:
            # Step 2: 从后向前找“替补” j
            j = n - 1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            
            # Step 3: 交换 i 和 j
            nums[i], nums[j] = nums[j], nums[i]
            
        # Step 4: 将 i 之后的全部元素反转（如果 i 是 -1，相当于反转整个数组）
        left = i + 1
        right = n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1