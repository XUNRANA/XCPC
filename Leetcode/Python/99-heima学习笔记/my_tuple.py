t1 = (1, "hello", False)
t2 = ()
t3 = tuple()

print(type(t1))
print(type(t2))
print(type(t3))

t4 = ("hello")
print(type(t4))
#单个元素时需要加入逗号
t4 = ("hello",)
print(type(t4))