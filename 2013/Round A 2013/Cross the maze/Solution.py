mp = []
Sq = []

def getLeft(d):
    if(d == 'N'):
        return 'W'
    if(d == 'E'):
        return 'N'
    if(d == 'S'):
        return 'E'
    return 'S'

def getRight(d):
    if(d == 'N'):
        return 'E'
    if(d == 'E'):
        return 'S'
    if(d == 'S'):
        return 'W'
    return 'N'

def getBack(d):
    if(d == 'N'):
        return 'S'
    if(d == 'E'):
        return 'W'
    if(d == 'S'):
        return 'N'
    return 'E'

def getIncoming(d):
    if(d == 'N'):
        return 0
    if(d == 'E'):
        return 1
    if(d == 'S'):
        return 2
    return 3

def checkBoundary(x, y, N, c):
    if((x + mp[getIncoming(c)][0]) < 0):
        return True
    if((y + mp[getIncoming(c)][1]) < 0):
        return True
    if((x + mp[getIncoming(c)][0]) == N):
        return True
    if((y + mp[getIncoming(c)][1]) == N):
        return True

    return False

def isStep(sx, sy, N, c):
    if(checkBoundary(sx, sy, N, c)):
        return False
    return (Sq[sx + mp[getIncoming(c)][0]][sy + mp[getIncoming(c)][1]] == '.')

mp.append([-1, 0])
mp.append([0, 1])
mp.append([1, 0])
mp.append([0, -1])

T = int(input())
for x in range(1, T + 1):
    N = int(input())
    Sq = []
    for i in range(0, N):
        s = input()
        Sq.append(s)
    
    sx, sy, ex, ey = [int(cr) for cr in input().split()]

    V = []
    for i in range(0, N):
        V.append([])
        for j in range(0, N):
            V[i].append([0,0,0,0])

    c = 'N'
    
    if((sx == N) and (sy == 1)):
        c = 'N'
    elif((sx == 1) and (sy == 1)):
        c = 'E'
    elif((sx == N) and (sy == N)):
        c = 'W'
    elif((sx == 1) and (sy == N)):
        c = 'S'
    
    sx -= 1
    sy -= 1
    ex -= 1
    ey -= 1

    path = ""
    ans = 0

    while(ans != -1):
        l = getLeft(c)
        if(isStep(sx, sy, N, l)):
            if(V[(sx + mp[getIncoming(l)][0])][sy + mp[getIncoming(l)][1]][getIncoming(l)] == 0):
                c = l
                sx += mp[getIncoming(l)][0]
                sy += mp[getIncoming(l)][1]
                V[sx][sy][getIncoming(l)] = 1
                ans += 1
                path += l
            else:
                ans = -1
                path = "Edison ran out of energy."
        else:
            l = c
            if(isStep(sx, sy, N, c)):
                if(V[(sx + mp[getIncoming(l)][0])][sy + mp[getIncoming(l)][1]][getIncoming(c)] == 0):
                    sx += mp[getIncoming(c)][0]
                    sy += mp[getIncoming(c)][1]
                    V[sx][sy][getIncoming(c)] = 1
                    ans += 1
                    path += c
                else:
                    ans = -1
                    path = "Edison ran out of energy."
            else:
                l = getRight(c)
                if(isStep(sx, sy, N, l)):
                    if(V[(sx + mp[getIncoming(l)][0])][sy + mp[getIncoming(l)][1]][getIncoming(l)] == 0):
                        c = l
                        sx += mp[getIncoming(l)][0]
                        sy += mp[getIncoming(l)][1]
                        V[sx][sy][getIncoming(l)] = 1
                        ans += 1
                        path += l
                    else:
                        ans = -1
                        path = "Edison ran out of energy."
                else:
                    l = getBack(c)
                    if(isStep(sx, sy, N, l)):
                        if(V[(sx + mp[getIncoming(l)][0])][sy + mp[getIncoming(l)][1]][getIncoming(l)] == 0):
                            c = l
                            sx += mp[getIncoming(l)][0]
                            sy += mp[getIncoming(l)][1]
                            V[sx][sy][getIncoming(l)] = 1
                            ans += 1
                            path += l
                        else:
                            ans = -1
                            path = "Edison ran out of energy."
                    else:
                        ans = -1
                        path = "Edison ran out of energy."
        if (sx is ex) and (sy is ey):
            break
    
    if ans > -1:
        print(f"Case #{x}: {ans}\n{path}")
    else:
        print(f"Case #{x}: {path}")
