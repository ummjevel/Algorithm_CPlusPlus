def solution(n):
    answer = 0
    
    f = [0, 1, 1]
    
    for i in range(3, n+1):
        f.append(f[len(f) - 2] + f[len(f) - 1])
    
    return f[-1]%1234567