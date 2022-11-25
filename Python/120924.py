def solution(common):
    answer = 0
    # 등차수열인지 등비수열인지.
    if len(common) >= 3:
        if (common[-1] - common[-2]) == (common[-2] - common[-3]):
            # 등차수열
            return common[-1] + common[-1] - common[-2]
        else:
            # 등비수열
            return common[-1] * (common[-1]//common[-2])
    return answer