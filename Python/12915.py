def solution(strings, n):
    answer = sorted(sorted(strings), key=lambda str: str[n])
    return answer