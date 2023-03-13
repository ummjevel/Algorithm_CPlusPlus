from collections import Counter

def solution(X, Y):
    answer = []
    x = Counter(X)
    y = Counter(Y)
    max_list = x
    min_list = y
    if len(x) < len(y):
        max_list = y
        min_list = x

    for key in min_list:
        if max_list[key] > 0:
            for i in range(min(max_list[key], min_list[key])):
                answer.append(key)
    if len(answer) == 0:
        return "-1"
    else:
        answer = sorted(answer, reverse=True)
        if answer[0] == '0':
            return "0"
        else:
            return ''.join(answer)

    '''
    answer = []
    max_list = list(X)
    min_list = list(Y)
    if len(X) < len(Y):
        max_list = list(Y)
        min_list = list(X)

    for i in range(len(min_list)):
        if min_list[i] in max_list:
            max_list.remove(min_list[i])
            answer.append(min_list[i])

    if len(answer) == 0:
        return "-1"
    else:
        answer = ''.join(sorted(answer, reverse=True))
        if int(answer) == 0:
            return "0"
        return answer
    '''
