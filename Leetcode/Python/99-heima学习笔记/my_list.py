a = ['lnu', '2022-2026', 'ecnu', '2026-2029', 100, 99.99, [1, 2, 3]]
print(a)

for i in a:
    print(type(i))

b = [[1, 2, 3], [4, 5, 6]]
print(b[-1])
print(type(b))

#查询下标
print(b.index([4, 5, 6]))

#修改
b[0] = [1, 2]
print(b)

#插入  [3]插入到下表为1的地方
b.insert(1, [3])
print(b)

#追加一个元素
b.append('i love you')
print(b)

#追加新列表
b.extend([1, 2, 3])
print(b)

#删除
del b[3]
print(b)

b.insert(3, 'i love you')
print(b)

#删除并且辅值
ele = b.pop(3)
print(ele)
print(b)

#从前到后删除第一个
b = [1, 2, 3, 2, 4, 4]
b.remove(4)
print(b)

count = b.count(1)
print(count)

#清空
b.clear()
#长度
print(len(b))