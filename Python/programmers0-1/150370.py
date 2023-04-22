def solution(today, terms, privacies):
    answer = []
    diterms = {}
    
    for term in terms:
        diterms[term.split(' ')[0]] = term.split(' ')[1]
        
    atoday = list(map(int, today.split('.')))
    
    for idx, privacy in enumerate(privacies):
        dates = list(map(int, privacy.split(' ')[0].split('.')))
        types = privacy.split(' ')[1]
        
        months = diterms[types]
        months = int(months)
        dates[0] += months//12 
        dates[1] += months%12
        if dates[1] > 12:
            dates[0] += dates[1]//12
            dates[1] = dates[1]%12
        if dates[2] - 1 == 0:
            dates[2] = 28
            dates[1] -= 1
        else:
            dates[2] -= 1
        
        if dates[0] < atoday[0] or (dates[0] <= atoday[0] and dates[1] < atoday[1]) or (dates[0] <= atoday[0] and dates[1] <= atoday[1] and dates[2] < atoday[2]):
            answer.append(idx+1)
    
    return answer