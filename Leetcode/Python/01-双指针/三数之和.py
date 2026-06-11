class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums = sorted(nums)
        n = len(nums)
        s = set()
        for i in range(n - 2):
            k = n - 1
            for j in range(i + 1, n - 1):
                if j >= k:
                    break
                while k >= 0 and nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                if j < k and nums[i] + nums[j] + nums[k] == 0:
                    s.add((nums[i], nums[j], nums[k]))

        return list(s)