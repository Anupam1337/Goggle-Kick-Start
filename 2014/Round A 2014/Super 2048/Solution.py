T = int(input())

for x in range(1, T + 1):
    N, DIR = input().split()
    N = int(N)
    board = []
    y = []
    for i in range(0, N):
        row = [int(item) for item in input().split()]
        board.append(row)
        row = [0] * N
        y.append(row)

    if DIR == "left":
        for i in range(0, N):
            s = 0
            k = 0
            for j in range(0, N):
                if(board[i][j] == 0):
                    continue
                if s == 0:
                    y[i][k] = board[i][j]
                    s = 1
                    k += 1
                else:
                    if y[i][k - 1] == board[i][j]:
                        y[i][k - 1] += board[i][j]
                        s = 0
                    else:
                        y[i][k] = board[i][j]
                        k += 1
    elif DIR == "right":
        for i in range(0, N):
            s = 0
            k = N - 1
            for j in range(N - 1, -1, -1):
                if board[i][j] == 0:
                    continue
                if s == 0:
                    y[i][k] = board[i][j]
                    s = 1
                    k -= 1
                else:
                    if y[i][k + 1] == board[i][j]:
                        y[i][k + 1] += board[i][j]
                        s = 0
                    else:
                        y[i][k] = board[i][j]
                        k -= 1
    elif DIR == "up":
        for i in range(0, N):
            s = 0
            k = 0
            for j in range(0, N):
                if board[j][i] == 0:
                    continue
                if s == 0:
                    y[k][i] = board[j][i]
                    s = 1
                    k += 1
                else:
                    if y[k - 1][i] == board[j][i]:
                        y[k - 1][i] += board[j][i]
                        s = 0
                    else:
                        y[k][i] = board[j][i]
                        k += 1
    elif DIR == "down":
        for i in range(0, N):
            s = 0
            k = N - 1
            for j in range(N - 1, -1, -1):
                if board[j][i] == 0:
                    continue
                if s == 0:
                    y[k][i] = board[j][i]
                    s = 1
                    k -= 1
                else:
                    if y[k + 1][i] == board[j][i]:
                        y[k + 1][i] += board[j][i]
                        s = 0
                    else:
                        y[k][i] = board[j][i]
                        k -= 1

    print(f"Case #{x}:")
    for i in range(0, N):
        for j in range(0, N):
            if j == N - 1:
                print(y[i][j])
            else:
                print(y[i][j], end = ' ')