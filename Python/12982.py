def solution(d, budget):
    answer = 0
    d = sorted(d)
    for i in d:
        budget -= i
        answer += 1
        if budget < 0:
            budget += i
            answer -= 1

    return answer