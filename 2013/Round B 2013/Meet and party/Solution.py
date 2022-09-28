B = x1 = y1 = x2 = y2 = 0
T = int(input())
for t in range(1, T + 1):
    B = int(input())
    x1, y1, x2, y2 = [int(item) for item in input().split()]
    x = y = d = 0
    print(f"Case #{t}: {x} {y} {d}")