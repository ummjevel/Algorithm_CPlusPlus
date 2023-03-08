from collections import Counter

def solution(participant, completion):
    p = Counter(sorted(participant))
    c = Counter(sorted(completion))

    for key in p:
        if p[key] > 1:
            if p[key] != c[key]:
                return key
        if c[key] == 0:
            return key


    '''
    answer = ''
    is_break = False
    for i in participant:
        if i not in completion:
            answer = i
            is_break = True
            break
        else:
            completion.remove(i)

    if is_break == True:
        return answer
    else:
        return completion[0]
    '''