import random
n = random.randint(1, 100)
count = 0
flag = True
while flag:
    guess_num = int(input("Guess a number:"))
    count += 1
    if guess_num == n:
        print("Right!")
        flag = False
    else:
        if guess_num > n:
            print("Bigger")
        else:
            print("Smaller")
print(count)