Analysis
---
For each query:

We can consider there are edges with weight 0 between every two nodes with same color.
Then we can run a Dijkstra algorithm to get the distance of shortest path. In that case the time complexity would be _O_(Q * N * log N + M) and space complexity would be _O_(N + M). In which N is the number of vertexes, M is the number of edges and Q is the number of query.

If we make the vertexes with same color into one single vertex, we can reduce the graph and then reduce the problem. In that case, the time complexity would be _O_(Q * C * log C + N + M). In which C is the number of different color.