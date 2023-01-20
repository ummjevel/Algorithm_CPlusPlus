def solution(a, b):
    small = min(a, b)
    big = max(a, b)
    s = 0
    for i in range(small, big + 1, 1):
        s = s + i
    if small == big:
        s = small
    return s