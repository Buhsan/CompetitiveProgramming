# def register_users(requests):
#     # Dictionary to keep track of usernames and their counts
#     user_db = {}
    
#     for name in requests:
#         if name not in user_db:
#             user_db[name] = 0
#             print("OK")
#         else:
#             user_db[name] += 1
#             new_name = name + str(user_db[name])
#             # while new_name in user_db:
#             #     user_db[name] += 1
#             #     new_name = name + str(user_db[name])
#             user_db[new_name] = 0
#             print(new_name)

# # Input handling
# n = int(input())  # number of requests
# requests = [input().strip() for _ in range(n)]

# # Process requests
# register_users(requests)

n = int(input())
list = [input().strip() for i in range(n)]

base = {}
    
for name in list:
    if name not in base:
        base[name] = 0
        print("OK")
    else:
        base[name] += 1
        new_name = name + str(base[name])
        base[new_name] = 0
        print(new_name)
        
