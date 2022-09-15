def DecimalToBinary(n):
    if n >= 1:
        return ("1" if(n%2 == 1) else "0") + DecimalToBinary(n // 2)
    else:
        return ""

T = int(input())
for x in range(1, T + 1):
    it = [int(item) for item in input().split()]

    if it[0] == 1:
        n = DecimalToBinary(it[1])
        p = 1
        q = 1
        for i in reversed(range(0, len(n) - 1)):
            if n[i] == '1':
                p += q
            else:
                q += p

        print(f"Case #{x}: {p} {q}", flush=True)
    
    else:
        n = 0
        i = 1
        p = it[1]
        q = it[2]

        while (p > 0) and (q > 0):
            if(p < q):
                q -= p
            else:
                p -= q
                n += i
            
            i <<= 1
        print(f"Case #{x}: {n}", flush=True)
