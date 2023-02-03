def solution(answers):
    answer = []
    temp1 = [1, 2, 3, 4, 5]
    temp2 = [2, 1, 2, 3, 2, 4, 2, 5]
    temp3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    temp1_score, temp2_score, temp3_score = 0, 0, 0
    for i in range(len(answers)):
        idx1 = i%len(temp1)
        idx2 = i%len(temp2)
        idx3 = i%len(temp3)
        if temp1[idx1] == answers[i]:
            temp1_score += 1
        if temp2[idx2] == answers[i]:
            temp2_score += 1
        if temp3[idx3] == answers[i]:
            temp3_score += 1

    temp_list = [temp1_score, temp2_score, temp3_score]
    for i in range(len(temp_list)):
        if temp_list[i] == max(temp_list):
            answer.append(i+1)
    return answer