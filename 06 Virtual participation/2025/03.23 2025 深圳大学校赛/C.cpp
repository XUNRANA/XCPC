import collections

for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    if k >= n: print(0); continue
    else:
        res = 0
        for i in range(0, k):
            cnt = collections.Counter(s[i:n:k])
            res += sum(cnt.values()) - max(cnt.values())
        print(res)
