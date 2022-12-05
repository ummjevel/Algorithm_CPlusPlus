def solution(quiz):
    answer = []

    for oquiz in quiz:
        quizes = oquiz.split(' ')
        if quizes[1] == '+':
            result = int(quizes[0]) + int(quizes[2])
        else:
            result = int(quizes[0]) - int(quizes[2])

        if result == int(quizes[-1]):
            answer.append("O")
        else:
            answer.append("X")

    return answer