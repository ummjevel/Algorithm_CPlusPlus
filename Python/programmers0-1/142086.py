def solution(s):
    answer = []
    dict_temp = {}
    for ss in range(len(s)):
        if s[ss] in dict_temp:
            answer.append(ss - dict_temp[s[ss]])
        else:
            answer.append(-1)
        dict_temp[s[ss]] = ss

    return answer