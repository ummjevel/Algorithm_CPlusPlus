def solution(num, total):
    answer = []

    temp = total//num
    if num%2 == 1:
        temp = temp - (num//2)
    else:
        temp = temp - (num//2) + 1

    for i in range(temp, temp + num):
        answer.append(i)

    return answer