def solution(ingredient):
    answer = 0
    form = [1, 2, 3, 1]
    i = 0
    while i + 3 < len(ingredient):
        if ingredient[i:i+4] == form:
            del ingredient[i:i+4]
            answer += 1
            i = i - 3
        i += 1
    return answer