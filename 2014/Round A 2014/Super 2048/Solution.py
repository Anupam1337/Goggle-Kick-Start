T = int(input())

for x in range(1, T + 1):
    N = int(input())
    board = []
    y = [[0] * N] * N
    for i in range(0, N):
        row = [int(item) for item in input().split()]
        board.append(row)

    print(f"Case #{x}:")
    for i in range(0, N):
        for j in range(0, N):
            if j == N - 1:
                print(y[i][j])
            else:
                print(y[i][j], end = ' ')