def solution(s):
    answer = ''
    for idx in range(len(s)):
        if idx != 0 and s[idx-1] == ' ' and s[idx].isalpha():
            answer += s[idx].upper()
        elif idx == 0 and s[idx].isalpha():
            answer += s[idx].upper()
        else:
            answer += s[idx].lower()

    return answer