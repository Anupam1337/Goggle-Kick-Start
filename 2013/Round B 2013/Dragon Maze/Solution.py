N = M = enx = eny = exx = exy = 0
maze = []

def isValid(x, y):
    return ((x >= 0) and (y >= 0) and (x < N) and (y < M))

def BFS():
    qu = [[enx, eny]]
    V = []
    R = []
    for i in range(0, N):
        R.append(maze[i][:])
        row = []
        for j in range(0, M):
            if maze[i][j] == -1:
                row.append(True)
            else:
                row.append(False)
        V.append(row)
    
    V[enx][eny] = True
    while(len(qu) > 0):
        temp = []
        while(len(qu) > 0):
            q = qu[0]
            qu.pop(0)
            x = q[0]
            y = q[1]
            val = R[x][y]

            if (exx == x) and (exy == y):
                return val
            
            if isValid(x - 1, y):
                if maze[x - 1][y] != -1:
                    R[x - 1][y] = max(R[x - 1][y], val + maze[x - 1][y])
                if V[x - 1][y] == False:
                    V[x - 1][y] = True
                    temp.append([x - 1, y])
            if isValid(x, y - 1):
                if maze[x][y - 1] != -1:
                    R[x][y - 1] = max(R[x][y - 1], val + maze[x][y - 1])
                if V[x][y - 1] == False:
                    V[x][y - 1] = True
                    temp.append([x, y - 1])
            if isValid(x + 1, y):
                if maze[x + 1][y] != -1:
                    R[x + 1][y] = max(R[x + 1][y], val + maze[x + 1][y])
                if V[x + 1][y] == False:
                    V[x + 1][y] = True
                    temp.append([x + 1, y])
            if isValid(x, y + 1):
                if maze[x][y + 1] != -1:
                    R[x][y + 1] = max(R[x][y + 1], val + maze[x][y + 1])
                if V[x][y + 1] == False:
                    V[x][y + 1] = True
                    temp.append([x, y + 1])
        qu = temp[:]

    return "Mission Impossible."

T = int(input())
for x in range(1, T + 1):
    N, M = [int(item) for item in input().split()]
    enx, eny, exx, exy = [int(item) for item in input().split()]
    maze = []
    for i in range(0, N):
        row = [int(item) for item in input().split()]
        maze.append(row)

    y = BFS()
    print(f"Case #{x}: {y}")