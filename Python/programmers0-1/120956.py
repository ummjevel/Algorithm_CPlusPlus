import re

def solution(babbling):
    answer = 0
    for i in range(len(babbling)):
        temp = babbling[i]
        babbling[i] = re.sub('aya|ye|woo|ma', '', temp)
    # print(babbling)
    answer = sum([1 for i in babbling if i == ''])
    return answer
