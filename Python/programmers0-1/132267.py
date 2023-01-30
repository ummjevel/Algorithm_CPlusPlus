def solution(a, b, n):
    answer = 0
    while n >= a:
        temp = n
        answer += temp // a * b
        n = temp % a  + temp // a * b

    return answer