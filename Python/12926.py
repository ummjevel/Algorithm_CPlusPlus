def solution(s, n):
    answer = ''
    for i in s:
        if i == ' ':
            answer += ' '
            continue
        if i.islower():
            temp = 97
        else:
            temp = 65
        answer += chr(temp + (((ord(i) + n) - temp) % 26))
    return answer