def solution(n,a,b):
    
    a -= 1
    b -= 1
    answer = 1
        
    while n != 2:
        if a//2 == b//2:
            break
        a = a//2
        b = b//2
        n = n//2
        answer += 1
    
    return answer