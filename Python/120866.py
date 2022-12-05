def solution(board):
    answer = 0
    tempboard = []
    for i in range(len(board)):
        temp = []
        for j in range(len(board)):
            temp.append(0)
        tempboard.append(temp)

    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 1:
                tempboard[i][j] = 1
                # print(i, j)
                up, down, left, right = i-1, i+2, j-1, j+2
                if up < 0: up = 0
                if down > len(board): down = len(board)
                if left < 0: left = 0
                if right > len(board): right = len(board)
                for k in range(up, down):
                    for l in range(left, right):
                        tempboard[k][l] = 1
                        # print(k, l)
    # print(tempboard)
    sum = 0
    for i in tempboard:
        # print(i)
        for j in i:
            if j == 1:
                sum += 1
    boardlen = len(board)**2
    # print(boardlen, sum)
    answer = boardlen - sum
    return answer