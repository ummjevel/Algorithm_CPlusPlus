from itertools import permutations
import math

def isPrime(number):
    if number < 2:
        return False

    for i in range(2, number):
        if number % i == 0:
            return False

    return True

def solution(numbers):
    answer = 0

    numbers = [int(i) for i in numbers]
    s = set()
    for num in range(1, len(numbers)+1):
        for i in list(permutations(numbers, num)):
            s.add(int(''.join(map(str, list(i)))))
    for i in s:
        if isPrime(i):
            answer += 1
    return answer