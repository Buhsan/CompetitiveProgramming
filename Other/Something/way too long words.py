n = int(input())
list = []
for i in range(n):
    a = input()
    b = len(a) 
    if b > 10:
        list.append(a[0] + str(b-2) + a[b-1])
    else:
        list.append(a)

for i in list:
    print(i)