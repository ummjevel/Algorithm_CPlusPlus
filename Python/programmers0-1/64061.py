def solution(board, moves):
    answer = 0
    box = []

    for move in moves:
        move = move - 1
        for i in range(len(board)):
            if board[i][move] != 0:
                if len(box) > 1:
                    if box[len(box) - 1] != board[i][move]:
                        box.append(board[i][move])
                    else:
                        del box[len(box) - 1]
                        answer += 2
                else:
                    box.append(board[i][move])

                board[i][move] = 0
                break
    if len(box) > 1:
        if box[0] == box[1]:
            answer += 2
    return answer