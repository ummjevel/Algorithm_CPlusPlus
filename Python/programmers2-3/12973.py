def solution(s):
    
    stack = []
    
    for str in s:
        if len(stack) == 0:
            stack.append(str)
        else:
            if stack[-1] == str:
                stack.pop()
            else:
                stack.append(str)
                
    if len(stack) > 0:
        return 0
    else:
        return 1
            
    
    
    '''
    answer = -1
    temp = s
    same_idx = 0
    is_same = False
    while True:
        for idx in range(1, len(temp)):
            if temp[idx-1] == temp[idx]:
                is_same = True
                same_idx = idx

        if is_same == True:
            temp = temp[0:same_idx-1] + temp[same_idx+1:]
        else:
            break
        is_same = False
        same_idx = 0
    if len(temp) == 0:
        return 1
    else:
        return 0
    '''
    