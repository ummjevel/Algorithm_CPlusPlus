def solution(s):
    answer = ''
    if len(s)%2 == 0:
        return s[int(len(s)/2-1)] + s[int(len(s)/2)]
    else:
        return s[int(len(s)/2)]