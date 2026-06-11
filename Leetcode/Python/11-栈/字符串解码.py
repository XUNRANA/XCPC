class Solution:
    def decodeString(self, s: str) -> str:
        multi = 0
        res = ""
        stack = []
        for char in s:
            if char.isdigit():
                multi = multi * 10 + int(char)
            elif char == '[':
                stack.append((res, multi))
                res = ""
                multi = 0
            elif char == ']':
                last_res, cur_multi = stack.pop()
                res = last_res + cur_multi * res
            else:
                res += char
        return res
            