n = int(input())
num = 0
for i in range(n):
    a, b, c = input().split(" ")
    if int(a)+int(b)+int(c) >= 2:
        num += 1

print(num)

    