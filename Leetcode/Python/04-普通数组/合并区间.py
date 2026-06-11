from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        l = intervals[0][0]
        r = intervals[0][1]

        ans = []
        for interval in intervals:
            if interval[0] <= r:
                r = max(r, interval[1])
            else:
                ans.append([l, r])
                l = interval[0]
                r = interval[1]

        ans.append([l, r])
        return ans
