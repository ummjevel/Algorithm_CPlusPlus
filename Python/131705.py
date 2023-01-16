def solution(number):
    answer = 0
    
    for i in range(len(number)):
        sum = number[i]
        for j in range(i+1, len(number)):
            sum += number[j]
            for k in range(j+1, len(number)):
                sum += number[k]
                if sum == 0:
                    answer += 1
                sum = number[i] + number[j]
            sum = number[i]
        
    return answer