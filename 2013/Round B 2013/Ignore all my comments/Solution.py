print("Case #1:")
c = 0
while True:
    try:
        S = input()
        N = len(S)
        i = 0
        while i < N:
            if((i < (N - 1)) and (S[i] == '/') and (S[i + 1] == '*')):
                i += 1
                c += 1
            elif((c > 0) and (i < (N - 1)) and (S[i] == '*') and (S[i + 1] == '/')):
                c -= 1
                i += 1
            elif(c == 0):
                print(S[i], end = '')
            i += 1
        if c == 0:
            print()

    except EOFError:
        break
