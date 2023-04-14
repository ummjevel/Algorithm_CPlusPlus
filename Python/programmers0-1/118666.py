def solution(survey, choices):
    answer = ''
    standard = {"R": 0, "T": 0, "C": 0, "F": 0, "J": 0, "M": 0, "A": 0, "N": 0}
    numbers = [0,3,2,1,0,1,2,3]
    for type, cho in zip(survey, choices):
        if cho < 4:
            standard[type[0]] += numbers[cho]
        else:
            standard[type[1]] += numbers[cho]
    if standard["R"] >= standard["T"]:
        answer += "R"
    else:
        answer += "T"
    if standard["C"] >= standard["F"]:
        answer += "C"
    else:
        answer += "F"
    if standard["J"] >= standard["M"]:
        answer += "J"
    else:
        answer += "M"
    if standard["A"] >= standard["N"]:
        answer += "A"
    else:
        answer += "N"
    return answer