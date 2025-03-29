n = int(input())
num = 0
for i in range(n):
    a = input()
    if (a.startswith("++") or a.endswith("++")):
        num+=1
    elif (a.startswith("--") or a.endswith("--")):
        num-=1

print(num)