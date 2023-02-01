def solution(n):
    answer = 0
    s = set(range(2, n+1))
    for i in range(2, n+1):
        if i in s:
            s -= set(range(2*i, n+1, i))
    answer = len(s)
    return answer

'''
# 효율성 실패

def solution(n):
    answer = 0
    for i in range(2, n + 1):
        flag = True
        for j in range(2, i):
            if i % j == 0:
                flag = False
                break
            if j * j > i:
                break
        if flag:
            answer += 1
    return answer

'''