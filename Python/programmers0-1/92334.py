def solution(id_list, report, k):
    answer = []
    stop_user = []
    mail = {key: 0 for key in id_list}
    selecting = {key: 0 for key in id_list}

    report = list(set(report))

    for re in report:
        selecting[re.split(" ")[1]] += 1

    for key, value in selecting.items():
        if value >= k:
            stop_user.append(key)

    for re in report:
        if re.split(" ")[1] in stop_user:
            mail[re.split(" ")[0]] += 1

    for i in id_list:
        answer.append(mail[i])

    return answer