def solution(numbers):
    answer = set()
    for idx1 in range(len(numbers)):
        for idx2 in range(len(numbers)):
            if idx1 != idx2:
                answer.add(numbers[idx1] + numbers[idx2])
    return sorted(list(answer))