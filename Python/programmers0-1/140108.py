def solution(s):
    answer = 1
    temp = s
    if len(s) == 1:
        return answer
    while len(temp) > 0:
        cnt1 = 1
        cnt2 = 0
        alpha1 = temp[0]
        for i in range(1, len(temp[1:])):
            if temp[i] == alpha1:
                cnt1 += 1
            else:
                cnt2 += 1
            if cnt1 == cnt2:
                answer += 1
                print(alpha1, temp[i])
                break
        temp = temp[i+1:]
        if len(temp) <= 1:
            break
    return answer