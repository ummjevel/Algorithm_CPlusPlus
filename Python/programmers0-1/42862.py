def solution(n, lost, reserve):
    answer = 0
    lost = sorted(lost)
    reserve = sorted(reserve)
    reserve_temp = reserve.copy()
    # 체육복 여분을 가진 학생이 여분이 있었을 경우
    for r in reserve:
        if r in lost:
            reserve_temp.remove(r)
            lost.remove(r)
    answer = n - len(lost)
    for l in lost:
        if l-1 in reserve_temp:
            reserve_temp.remove(l-1)
            answer += 1
        elif l+1 in reserve_temp:
            reserve_temp.remove(l+1)
            answer += 1

    return answer