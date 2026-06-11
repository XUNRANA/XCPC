

my_set = {1, 1, 1, 3, 2, 4}
my_set_empty = set()


print(my_set)
print(my_set_empty)


my_set_empty.add(1)
print(my_set_empty)

my_set_empty.remove(1)
print(my_set_empty)

print(my_set.pop())
print(my_set)


s1 = {1, 2, 3}
s2 = {2, 3, 4}

# in s1  and  not in s2
s3 = s1.difference(s2)
print(s3)
# del i from s1 in s2
s1.difference_update(s2)
print(s1)

#union
s3 = s1.union(s2)
print(s3)