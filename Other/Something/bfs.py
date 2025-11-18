from queue import Queue

def bfs(start, end, adj, prev):
    visited = set()
    pair = (start, 0)
    q = Queue()
    visited.add(start);
    q.put(pair)

    while not q.empty():
        node = q.get()
        pos = node[0]
        moves = node[1]

        if pos == end:
            return moves


        for vecino in adj[pos]:
            if vecino not in visited:
                visited.add(vecino)
                aux = (vecino, moves+1)
                prev[vecino] = pos;
                q.put(aux)


    return -1


    

# n, m = input().split(" ")
n, m = map(int, input().split(" "))
# n = int(n)
# m = int(m)
adj = [[] for _ in range(n)]
prev = [-1 for _ in range(n)]

start = 7
end = 6

for i in range(m):
    a, b = map(int, input().split(" "))
    adj[a].append(b)
    adj[b].append(a)

# for i in adj:
#     print(i);


result = bfs(start, end, adj, prev)

current = end
path = [end]

while(prev[current] != -1):
    path.insert(0, prev[current])
    current = prev[current]

size = len(path)
print("Length of the path:", result)
for i in range(size):
    print(path[i], end='\n' if i == size-1 else ' --> ')
    
    
