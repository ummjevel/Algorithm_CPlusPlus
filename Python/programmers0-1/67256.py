def solution(numbers, hand):
    answer = ''
    cur_left = 10
    cur_right = 12
    
    pad_tuple = [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2)
                 , (2, 0), (2, 1), (2, 2), (3, 0), (3, 1), (3, 2)]
    for num in numbers:
        if num == 0:
            num = 11
        if num in [1, 4, 7]:
            answer += 'L'
            cur_left = num
        elif num in [3, 6, 9]:
            answer += 'R'
            cur_right = num
        else:
            right_0 = abs(pad_tuple[num - 1][0] - pad_tuple[cur_right - 1][0])
            right_1 = abs(pad_tuple[num - 1][1] - pad_tuple[cur_right - 1][1])
            right = right_0 + right_1
            left_0 = abs(pad_tuple[num - 1][0] - pad_tuple[cur_left - 1][0])
            left_1 = abs(pad_tuple[num - 1][1] - pad_tuple[cur_left - 1][1])
            left = left_0 + left_1
            
            if right == left:
                if hand == "left":
                    answer += 'L'
                    cur_left = num
                else:
                    answer += 'R'
                    cur_right = num
            elif left > right:
                answer += 'R'
                cur_right = num
            else:
                answer += 'L'
                cur_left = num
            
    return answer