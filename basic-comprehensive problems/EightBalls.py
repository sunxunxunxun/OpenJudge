#https://acm.uestc.edu.cn/problem/8qiu-sheng-fu-eight/description
while 1:
    n = int(input())
    if n == 0:
        break
    s = input()
    cnt_R = 0
    cnt_Y = 0
    for ch in s:
        if (ch == 'B' and cnt_R == 7) | (ch == 'L' and cnt_Y != 7):
            print("Red")
        elif (ch == 'L' and cnt_Y == 7) | (ch == 'B' and cnt_R != 7):
            print("Yellow")
        elif ch == 'R':
            cnt_R += 1
        elif ch == 'Y':
            cnt_Y += 1




