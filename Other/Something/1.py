# def max_happy_people(n, r, family_members):
#     family_members.sort(reverse=True)  # Sort families by size in decreasing order
#     happy_people = 0
#     total_rows = r
    
#     # Count how many full rows we can fill and the remaining individuals
#     rows_filled = 0
#     remaining = []
    
#     for members in family_members:
#         if members % 2 == 0:
#             happy_people += members  # All of them can sit in pairs
#         else:
#             happy_people += members - 1  # All but one can sit in pairs
#             remaining.append(1)  # One member is left unpaired
    
#     # Now we need to seat the remaining individuals
#     # We can sit two remaining individuals in one row to make them both happy
#     remaining_seats = total_rows * 2 - sum(family_members)  # empty seats left after placing pairs
    
#     happy_people += min(len(remaining), remaining_seats)
    
#     return happy_people

# def main():
#     t = int(input())  # number of test cases
#     for _ in range(t):
#         n, r = map(int, input().split())  # number of families and rows
#         family_members = list(map(int, input().split()))  # number of family members in each family
        
#         # Output the result for each test case
#         print(max_happy_people(n, r, family_members))

# # Example of running this code
# main()















n = int(input())


def isEven(number):
    if (number % 2) == 0:
        return True
    else:
        return False
    
def sorted_lsit(l):
    a = []
    for i in l:
        a.append(int(i))
    a.sort(reverse=True)
    return a

    

for i in range(n):
    a, b = input().split(" ")
    list = input().split(" ")
    happy = 0
    summ=0
    count = int(b)*2
    listado = sorted_lsit(list)
    left = []
    index = 0
    for j in listado:
        num = int(j)
        index += 1
        summ+=num
        if isEven(num):
            happy += num
        else:
            happy += (num - 1)
            left.append(1)
        rest = count - summ
        if(index == len(listado)):
            if rest < len(left):
                happy += rest
            elif rest > len(left):
                happy += len(left)
            else:
                happy += len(left)

    print(happy)
    
        



# if isEven(num) and num <= count:
        #     count-=num
        #     happy += num
        # elif isEven(num) and num > count:
        #     count -= (num-count)
        #     if isEven((num-count)):
        #         happy += (num-count)

        # if not isEven(num) and num+1 < count:
        #     count-=num+1
        #     happy += num
        # elif not isEven(num) and num >= count:
        #     count-=num
