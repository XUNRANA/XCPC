class Solution:

    def expand(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return (right - left - 2) // 2
    def longestPalindrome(self, s: str) -> str:
        end, start = -1, 0
        s = "#" + "#".join(list(s)) + "#"
        arm_len = []
        right = -1
        j = -1
        for i in range(len(s)):
            if right >= i:
                i_sym = 2 * j - i
                min_arm_len = min(arm_len[i_sym], right - i)
                cur_arm_len = self.expand(s, i - min_arm_len, i + min_arm_len)
            else:
                cur_arm_len = self.expand(s, i, i)
            arm_len.append(cur_arm_len)
            if i + cur_arm_len > right:
                j = i
                right = i + cur_arm_len
            if 2 * cur_arm_len + 1 > end - start:
                start = i - cur_arm_len
                end = i + cur_arm_len
        return s[start + 1: end + 1: 2]
    # def longestPalindrome(self, s: str) -> str:
    #     n = len(s)
    #     if n < 2:
    #         return s 
    #     max_len = 1
    #     begin = 0
    #     dp = [[False] * n for _ in range(n)]
    #     for i in range(n):
    #         dp[i][i] = True
        
    #     # len
    #     for L in range(2, n + 1):
    #         # left
    #         for i in range(n):
    #             # right
    #             j = L + i - 1
    #             if j >= n:
    #                 break
    #             if s[i] != s[j]:
    #                 dp[i][j] = False
    #             else:
    #                 if j - i < 3:
    #                     dp[i][j] = True
    #                 else:
    #                     dp[i][j] = dp[i + 1][j - 1]
    #             if dp[i][j] and j - i + 1 > max_len:
    #                 max_len = j - i + 1
    #                 begin = i
    #     return s[begin: begin + max_len]
