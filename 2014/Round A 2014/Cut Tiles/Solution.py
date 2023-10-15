T = int(input())
for x in range(1, T + 1):
    y = 0
    required = [int(item) for item in input().split()]
    N = required.pop()
    M = required.pop()
    st = []
    while(len(required) > 0):
        if(len(st) == 0):
            st.append([M, M])
            y += 1
        
        N = len(required)
        for i in range(N - 1, -1, -1):
            for j in range(0, len(st)):
                if st[j][0] < required[i]:
                    continue
                p = st[j]
                st.pop(j)

                if p[0] == required[i]:
                    if p[1] > required[1]:
                        st.append([min(p[1] - p[0], p[0]), max(p[1] - p[0], p[0])])
                else:
                    m1 = p[0] - required[i]
                    m2 = p[1] - required[i]
                    st.append([min(m1, m2), max(m1, m2)])
                    st.append([min(m1, required[i]), max(m1, required[i])])
                    st.append([min(m2, required[i]), max(m2, required[i])])
                required.pop(i)
                st.sort()
        if(len(required) == N):
            break
        st = []
    print(f"Case #{x}: {y}")