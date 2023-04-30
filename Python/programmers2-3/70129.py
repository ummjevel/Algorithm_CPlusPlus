def solution(s):
    answer = []
    temp = s
    cnt = 0
    total_cnt = 0

    while temp != "1":
        temp_one = ""
        for st in temp:
            if st == "0":
                cnt += 1
            else:
                temp_one  += "1"

        temp2 = len(temp_one)
        save = ""
        while temp2 >= 1:
            save = str(temp2%2) + save
            temp2 = temp2//2
        temp = save

        total_cnt += 1

    return [total_cnt, cnt]