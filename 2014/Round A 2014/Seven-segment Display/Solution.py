digits = ["1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"]

T = int(input())
for x in range(1, T + 1):
    states = input().split()
    N = int(states.pop(0))
    y = ""
    mp = {n: "2222222" for n in range(10)}

    for i in range(N):
        mpr = {}
        for disp, led in mp.items():
            flag = 1

            for k in range(7):
                if(states[i][k] == '1'):
                    if(digits[disp][k] == '0') or (led[k] == '0'):
                        flag = 0
                        break
                    led = led[:k] + '1' + led[k + 1:]
                elif digits[disp][k] == '1':
                    if led[k] == '1':
                        flag = 0
                        break
                    led = led[:k] + '0' + led[k + 1:]
            if flag == 1:
                mpr[(disp + 9) % 10] = led
        mp = mpr.copy()
    for disp, led in mp.items():
        ans = digits[disp]
        
        for k in range(7):
            if (ans[k] == '1') and (led[k] == '2'):
                ans = "ERROR!"
                break
            if led[k] == '0':
                ans = ans[:k] + '0' + ans[k + 1:]
        if y == "":
            y = ans
        if y != ans:
            y = "ERROR!"
    
    if y == "":
        y = "ERROR!"
    print(f"Case #{x}: {y}")