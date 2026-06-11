my_dict1 = {1:2, 2:3, 3:4}
my_dict2 = {}
my_dict3 = dict()
print(type(my_dict1))
print(type(my_dict2))
print(type(my_dict3))
my_dict1[4] = 5
print(my_dict1)
#value
print(my_dict1.pop(3))
print(my_dict1)


keys = my_dict1.keys()
print(type(keys))
print(keys)