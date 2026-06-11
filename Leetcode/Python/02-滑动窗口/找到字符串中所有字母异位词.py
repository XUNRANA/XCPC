from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        s_count = [0] * 26
        p_count = [0] * 26
        for ch in p:
            p_count[ord(ch) - ord('a')] += 1
        
        ans = []
        ns = len(s)
        np = len(p)
        for i in range(0, ns):
            s_count[ord(s[i]) - ord('a')] += 1
            if i >= np:
                s_count[ord(s[i - np]) - ord('a')] -= 1
            if p_count == s_count:
                ans.append(i - np + 1)
        return ans

