def conv2bi(numbers):
    return [bin(number) for number in numbers]


def convbi2str(number1, number2):
    result = ''
    for num1, num2 in zip(number1, number2):
        if int(num1) + int(num2) != 0:
            result += "#"
        else:
            result += " "
    return result


def solution(n, arr1, arr2):
    answer = []
    # AND 연산하기
    temp_arr1, temp_arr2 = [], []
    for number1, number2 in zip(arr1, arr2):
        # 2진수로 바꾸기
        temp_arr1.append(format(number1, 'b'))
        temp_arr2.append(format(number2, 'b'))
    # fixed length
    max_length = 0
    for number1, number2 in zip(temp_arr1, temp_arr2):
        max_length = max(len(number1), len(number2), max_length)
    temp_arr1, temp_arr2 = [], []
    for number1, number2 in zip(arr1, arr2):
        temp_arr1.append(f'{number1:0{max_length}b}')
        temp_arr2.append(f'{number2:0{max_length}b}')
    # AND
    for number1, number2 in zip(temp_arr1, temp_arr2):
        answer.append(convbi2str(number1, number2))
    # # 과 공백으로 대체하기
    return answer