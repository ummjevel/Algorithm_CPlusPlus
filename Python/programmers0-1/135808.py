def solution(k, m, score):
    answer = 0
    results = [0]
    score = sorted(score, reverse=True)
    for i in range(0, len(score) - m + 1, m):
        results.append(min(score[i:i+m]))
    answer = sum(list(map(lambda x:x*m, results)))
    return answer