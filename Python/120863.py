def solution(polynomial):
    answer = ''
    coef = 0
    number = 0
    for i in polynomial.split(' '):
        if i == '+':
            continue
        if i[-1] == 'x':
            if len(i) == 1:
                coef += 1
            else:
                coef += int(i[:-1])
        else:
            number += int(i)
    
    if coef > 1:
        answer = str(coef) + 'x'
    elif coef == 1:
        answer = 'x'
    
    if number != 0:
        if coef >= 1:
            answer += ' + ' + str(number)
        else:
            answer += str(number)
        
    if coef == 0 and number == 0:
        answer += '0'
    return answer