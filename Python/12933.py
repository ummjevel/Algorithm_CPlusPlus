def solution(n):
    answer = 0
    return int(''.join(sorted([i for i in str(n)], reverse=True)))