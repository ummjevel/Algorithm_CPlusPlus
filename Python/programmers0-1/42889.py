def solution(N, stages):
    temp_answer = {}
    for i in range(1, N+1):
        cnt = 0
        temp = 0
        for j in stages:
            if j >= i:
                cnt += 1
            if j == i:
                temp += 1
        if temp == 0 or cnt == 0:
            temp_answer[i] = 0.0 
        else:
            temp_answer[i] = temp/cnt
    
    answer = [i for i, j in sorted(temp_answer.items(), key=lambda item: item[1], reverse=True)]
    return answer