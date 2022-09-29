T = int(input())

def getBlue(i, N, S):
    if(i == N):
        return 0
    if(S[i][0] != 'B'):
        return getBlue(i + 1, N, S)
    st = []
    st.append([i, 0])
    while(len(st) > 0):
        p = st.pop()
        j = p[0]
        k = p[1]
        S[j][k] = '.'
        if(k == (N - 1)):
            return 1 + getBlue(i + 1, N, S)

        if((k > 0) and (S[j][k - 1] == 'B')):
            st.append([j, k - 1])
        if((j < (N - 1)) and (k > 0) and (S[j + 1][k - 1] == 'B')):
            st.append([j + 1, k - 1])
        if((j < (N - 1)) and (S[j + 1][k] == 'B')):
            st.append([j + 1, k])
        if((k < (N - 1)) and (S[j][k + 1] == 'B')):
            st.append([j, k + 1])
        if((j > 0) and (S[j - 1][k] == 'B')):
            st.append([j - 1, k])
        if((j > 0) and (k < (N - 1)) and (S[j - 1][k + 1] == 'B')):
            st.append([j - 1, k + 1])
    return getBlue(i + 1, N, S)

def getRed(j, N, S):
    if(j == N):
        return 0
    if(S[0][j] != 'R'):
        return getRed(j + 1, N, S)

    st = []
    st.append([0, j])
    while(len(st) > 0):
        p = st[len(st) - 1]
        st.pop()
        i = p[0]
        k = [1]
        S[i][k] = '.'
        if(i == (N - 1)):
            return 1 + getRed(j + 1, N, S)

        if((i > 0) and (k < (N - 1)) and (S[i - 1][k + 1] == 'R')):
            st.append[i - 1][k + 1]
        if((i > 0) and (S[i - 1][k] == 'R')):
            st.append[i - 1][k]
        if((k < (N - 1)) and (S[i][k + 1] == 'R')):
            st.append[i][k + 1]
        if((k > 0) and (S[i][k - 1] == 'R')):
            st.append[i][k - 1]
        if((i < (N - 1)) and (S[i + 1][k] == 'R')):
            st.append[i + 1][k]
        if((i < (N - 1)) and (k > 0) and (S[i + 1][k - 1] == 'R')):
            st.append[i + 1][k - 1]

    return getRed(i + 1, N, S)

for x in range(1, T + 1):
    N = int(input())
    board = []
    B = 0
    R = 0
    Bl = 0
    Rl = 0
    y = "Nobody wins"
    for i in range(0, N):
        s = input()
        board.append([*s])
        for j in range(0, N):
            if board[i][j] == 'B':
                B += 1

    Bl = getBlue(0, N, board)
    Rl = getRed(0, N, board)
    if(abs(R - B) > 1):
        y = "Impossible"
    elif((Bl + Rl) > 1):
        y = "Impossible"
    elif((Bl == 1) and (B < R)):
        y = "Impossible"
    elif((Rl == 1) and (R < B)):
        y = "Impossible"
    elif(Bl == 1):
        y = "Blue wins"
    elif(Rl == 1):
        y = "Red wins"
    print(f"Case #{x}: {y}")