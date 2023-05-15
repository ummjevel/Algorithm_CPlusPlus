def solution(s):
    answer = 0
    for i in range(len(s)):
        temp = list(s[i:] + s[0:i])
        list_temp = []
        
        for str in temp:
            if len(list_temp) == 0:
                list_temp.append(str)
            elif list_temp[-1] + str in ["[]", "{}", "()"]:
                list_temp.pop()
            else:
                list_temp.append(str)
                
        if len(list_temp) == 0:
            answer += 1
        
    return answer