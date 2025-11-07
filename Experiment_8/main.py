import heapq

class Solution:
    def dijkstra(self, V, edges, src):
        adj = [[] for _ in range(V)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
            
        dist = [float('inf')] * V
        dist[src] = 0
        heap = [(0, src)]
        
        while heap:
            d, node = heapq.heappop(heap)
            if d > dist[node]:
                continue
            for nei, w in adj[node]:
                if dist[node] + w < dist[nei]:
                    dist[nei] = dist[node] + w
                    heapq.heappush(heap, (dist[nei], nei))
        
        return dist
