def solution(n):
    answer = 0
    
    for start_point in range(1, n+1):
        su = 0
        for point in range(start_point, n+2):
            if su < n:
                su += point
            elif su == n:
                answer += 1
                break
            else:
                break
    
    return answer