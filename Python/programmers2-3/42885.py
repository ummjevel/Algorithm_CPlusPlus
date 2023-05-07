from collections import deque

def solution(people, limit):
    answer = 0
    people = deque(sorted(people))
    
    while len(people) > 1:
        if people[0] + people[-1] <= limit:
            people.popleft()
        people.pop()
        answer += 1
        
    if len(people) == 1:
        answer += 1
        
    return answer