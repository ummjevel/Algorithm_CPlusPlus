def solution(name, yearning, photo):
    answer = []
    # 교집합
    for i in photo:
        new_s = set(name) & set(i)
        temp = 0
        for i in new_s:
            temp += yearning[name.index(i)]
        answer.append(temp)
    return answer