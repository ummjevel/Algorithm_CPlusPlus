def solution(lottos, win_nums):
    answer = []
    if 0 in lottos:
        cnt = sum([1 for i in lottos if i == 0]) 
        rank = 7 - len(set(lottos).intersection(set(win_nums))) 
        answer.append(rank - cnt)
        if rank == 7:
            rank = 6
        answer.append(rank)

    else:
        rank = 7 - len(set(lottos).intersection(set(win_nums)))
        if rank == 7:
            rank = 6
        answer.append(rank)
        answer.append(rank)
    return answer