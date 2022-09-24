T = int(input())
for x in range(1, T + 1):
    N = int(input())
    sudoku = []
    values = set(range(1, N ** 2 + 1))
    y = "Yes"
    flag = True
    for i in range(0, N ** 2):
        sudoku.append(list(map(int, input().split())))
        if flag:
            if set(sudoku[i]) != values:
                flag = False
                y = "No"
    
    if flag:
        for i in range(0, N ** 2):
            col = []
            for j in range(0, N ** 2):
                col.append(sudoku[j][i])
            if set(col) != values:
                flag = False
                y = "No"
                break
    
    if flag:
        for i in range(0, N):
            for j in range(0, N):
                block = []
                for k in range(0, N):
                    for l in range(0, N):
                        block.append(sudoku[(i * N) + k][(j * N) + l])
                
                if set(block) != values:
                    flag = False
                    y = "No"
                    break
            if flag == False:
                break
    
    print(f"Case #{x}: {y}")
