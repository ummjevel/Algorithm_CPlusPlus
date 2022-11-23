def solution(n):
    temp = 0
    cnt = 0
    while cnt < n:
        if temp%3 == 0:
            temp += 1
            continue
        if '3' in str(temp):
            temp += 1
            continue
        temp += 1
        cnt += 1
    return temp - 1
    