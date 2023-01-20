def solution(s):
    answer = ''
    cnt = 0
    for i in range(len(s)):
        if s[i] == ' ':
            cnt = 0
            answer += ' '
            continue
        if cnt % 2 == 1:
            answer += s[i].lower()
        else:
            answer += s[i].upper()
        cnt += 1

    return answer