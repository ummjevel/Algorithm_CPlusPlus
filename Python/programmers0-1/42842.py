def solution(brown, yellow):
    answer = []
    
    xy = brown + yellow
    xplusy = int(brown/2) + 2
    
    for x in range(1, xplusy):
        for y in range(1, xplusy):
            if x+y == xplusy and x*y == xy:
                if x >= y:
                    answer = [x, y]
                    return answer