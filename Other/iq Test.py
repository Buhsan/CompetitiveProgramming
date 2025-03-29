n = int(input())
a = input().split(" ")
nums = []

even = 0
odd = 0

res = 0
res_dif = -1

def isEven(number):
    if (number % 2) == 0:
        return True
    else:
        return False
    
def find_even_odd(list, caract):
    if caract == 0:
        for i in list:
            if isEven(i):
                return list.index(i)
    else:
        for i in list:
            if not(isEven(i)):
                return list.index(i)

    
for j in a:
    nums.append(int(j))
    if isEven(int(j)):
        even += 1
    else:
        odd +=1

if (min(even,odd) == even):
    print(find_even_odd(nums, 0) + 1)
else:
    print(find_even_odd(nums, 1) + 1)

    
