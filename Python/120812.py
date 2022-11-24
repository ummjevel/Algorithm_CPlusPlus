from collections import Counter

def solution(array):
    answer = -1
    count = dict(Counter(array))
    max_count = 0
    max_key = -1
    max_value = max(count.values())
    for i in array:
        if count[i] == max_value:
            max_count += 1
            max_key = i
    if max_count > max_value:
        return -1
    return max_key