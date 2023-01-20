def solution(arr1, arr2):
    answer = []
    for i in range(len(arr1)):
        result = []
        for j in range(len(arr1[0])):
            arr = arr1[i][j] + arr2[i][j]
            result.append(arr)
        answer.append(result)
    return answer