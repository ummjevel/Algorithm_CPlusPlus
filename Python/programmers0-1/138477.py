def solution(k, score):
    answer = []
    temp = []
    for i in score:
        temp.append(i)
        temp = sorted(temp, reverse=True)[0:k]
        answer.append(temp[-1])
    return answer