def solution(players, callings):

    answer = [""]*len(players)
    rank = {}
    rank2name = {}
    for idx, player in enumerate(players):
        rank[player] = idx
        rank2name[idx] = player

    for calling in callings:
        cur_idx = rank[calling]
        next_idx = cur_idx - 1
        next_player = rank2name[next_idx]
        rank[next_player] = cur_idx
        rank[calling] = next_idx
        rank2name[next_idx] = calling
        rank2name[cur_idx] = next_player

    for key, value in rank2name.items():
        answer[key] = value 

    return answer

    '''
    answer = []
    temp_players = players
    for calling in callings:
        idx = temp_players.index(calling)
        back_player = temp_players[idx-1]
        temp_players[idx] = back_player
        temp_players[idx-1] = calling

    answer = temp_players
    return answer


    answer = []
    temp_players = players
    for calling in callings:
        temp = []
        for i in range(len(temp_players)):
            if temp_players[i] == calling:
                continue

            if i == len(temp_players) - 1:
                temp.append(temp_players[i])
                continue

            if temp_players[i+1] == calling:
                temp.extend([calling, temp_players[i]])
            else:
                temp.append(temp_players[i])

        temp_players = temp

    answer = temp_players
    return answer
    '''
