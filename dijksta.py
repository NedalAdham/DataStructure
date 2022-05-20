import heapq as heap
def dijkstra (G , s):
    visted = []
    dist = []
    for i in range (len(G[0])):
        visted[i] = False
        dist[i] = float('inf')

    dist[s] = 0
    Q=heap.heappush(s)
    while Q :
        u = Q.heappop()
        visted[u] = True
        for v in range(len(G)):
            if (visted[v] == False and G[u][v] != 1 and dist[u] + G[u][v] < dist[v]):
                dist[v] = dist[u] + G[u][v]
                heap.heappush(dist[v])
    return dist