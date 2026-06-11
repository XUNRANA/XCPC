import heapq
import random
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pivot = random.choice(nums)
        big = [x for x in nums if x > pivot]
        equal = [x for x in nums if x == pivot]
        small = [x for x in nums if x < pivot]
        if k <= len(big):
            return self.findKthLargest(big, k)
        elif k > len(big) + len(equal):
            return self.findKthLargest(small, k - len(big) - len(equal))
        else:
            return pivot
    

    def findKthLargest(self, nums: List[int], k: int) -> int:
        # 截取前 k 个元素，并在原地转化为最小堆
        min_heap = nums[:k]
        heapq.heapify(min_heap)
        
        # 从第 k+1 个元素开始遍历
        for x in nums[k:]:
            # 只有当当前元素大于堆顶元素时，才有资格入堆替换
            if x > min_heap[0]:
                heapq.heappushpop(min_heap, x)
                
        # 最后堆顶留下的就是第 k 大的元素
        return min_heap[0]
        