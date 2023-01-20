from collections import Counter



'''
def solution(lines):
    answer = 0
    cnt = Counter()
    for line in lines:
        cnt += Counter(range(min(line), max(line)))
    return sum([c > 1 for c in cnt.values()])
'''