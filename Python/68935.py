def solution(n):
    answer = 0
    temp = ''

    # 3진법으로 뒤집어서 만들기
    while n > 0:
        temp += str(n%3)
        n = n//3

    # 10진법으로 만들기
    b = 1
    for i in temp[::-1]:
        answer = answer + int(i) * b
        b = b * 3

    return answer