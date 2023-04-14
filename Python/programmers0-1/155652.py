def solution(s, skip, index):
    answer = ''
    cha = "abcdefghijklmnopqrstuvwxyz"
    for ch in s:
        fix_start = cha.index(ch)
        fix_end = fix_start + index
        current_idx = fix_start
        while fix_start < fix_end:
            idx = (current_idx + 1)%len(cha)
            if cha[idx] in skip:
                fix_end += 1
            current_idx += 1
            fix_start += 1
        answer += cha[idx]
    return answer