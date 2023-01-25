def solution(a, b):
    weekdays = {1: "FRI", 2: "SAT", 3:"SUN", 4:"MON", 5:"TUE", 6:"WED", 0:"THU"}
    months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    return weekdays[(sum(months[0:a-1]) + b) % 7]