def fastPow(a, b):
    res = 1
    while b:
        if b & 1:
            res = res * a
        a = a * a
        b >>= 1
    return res

t = int(input())

for _ in range(t):
    n = int(input()) 
    res = (fastPow(n,4) - 6*fastPow(n,3) + 23*fastPow(n,2) - 18*n + 24)//24
    print(res)


# 1 2 3 5 8
