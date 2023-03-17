import math

def solution(number, limit, power):
    answer = 0
    temp = []
    # 약수 구하기
    for i in range(1, number + 1):
        cnt = 0
        for j in range(1, int(math.sqrt(i)) + 1):
            if j*j == i:
                cnt += 1
            elif i%j == 0:
                cnt += 2

        # limit 넘는 것은 power로 대체.
        if cnt > limit:
            cnt = power
        temp.append(cnt) 
    answer = sum(temp)
    return answer