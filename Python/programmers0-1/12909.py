def solution(s):
    
    cnt = 0
    for idx in range(len(s)):
        if idx == 0 and s[idx] == ")":
            return False
        if cnt < 0:
            return False
        if s[idx] == "(":
            cnt += 1
        else:
            cnt -= 1

    if cnt == 0:
        return True
    else:
        return False
    