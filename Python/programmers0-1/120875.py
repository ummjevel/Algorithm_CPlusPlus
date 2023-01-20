def slope(x, y):
    x1 = x[0]
    y1 = x[1]
    x2 = y[0]
    y2 = y[1]

    x3 = x2 - x1
    y3 = y2 - y1
    return x3 / y3

def solution(dots):
    answer = 0

    s1 = slope(dots[0], dots[1])   
    s2 = slope(dots[2], dots[3])

    if s1 == s2:
         return 1

    s3 = slope(dots[0], dots[2])
    s4 = slope(dots[1], dots[3])

    if s3 == s4:
        return 1

    s5 = slope(dots[1], dots[2])
    s6 = slope(dots[0], dots[3])

    if s5 == s6:
        return 1

    return answer