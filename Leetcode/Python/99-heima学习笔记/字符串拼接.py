year = 2000
age = 26
message = "欧阳兴隆,%d岁,生于%d年。" % (age, year)
print(message)


message = f"欧阳兴隆,{ age }岁,生于{        year           }年。"
print(message)

print("字符串的类型是：%s" % type("字符串"))

print("字符串的类型是：%s" % type('字符串'))

print("字符串的类型是：%s" % type('''字符串'''))