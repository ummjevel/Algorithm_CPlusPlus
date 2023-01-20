def solution(absolutes, signs):
    answer = 0
    
    for ab, sig in zip(absolutes, signs):
        if sig == False:
            ab = ab * -1
        answer += ab

    return answer