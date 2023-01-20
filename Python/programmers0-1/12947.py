def solution(x):
    if x % sum([int(i) for i in str(x)]) == 0:
        answer = True
    else:
        answer = False

    return answer