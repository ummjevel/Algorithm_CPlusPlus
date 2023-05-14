from collections import Counter

def solution(k, tangerine):
    answer = 0
    temp = {k: v for k, v in sorted(Counter(tangerine).items(), key=lambda item: item[1], reverse=True)}
    cnt = 0
    for i, j in temp.items():
        cnt += j
        answer += 1
        if cnt >= k:
            break
    
    return answer