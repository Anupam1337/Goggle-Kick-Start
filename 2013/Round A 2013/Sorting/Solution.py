# cook your dish here
T = int(input())
for x in range(1, T + 1):
    N = int(input())
    S = [int(item) for item in input().split()]

    evenlist = []
    oddlist = []
    for i in S:
        if(i % 2 == 0): 
            evenlist.append(i) 
        else:
            oddlist.append(i)
    
    evenlist = sorted(evenlist, reverse = True)
    oddlist = sorted(oddlist)

    j = 0
    k = 0
    for i in range(0, N):
        if(S[i] % 2 == 0):
            S[i] = evenlist[j]
            j = j + 1
        else:
            S[i] = oddlist[k]
            k = k + 1

    print(f"Case #{x}: " + (' '.join(map(str, S))))