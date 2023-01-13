def solution(sizes):
    answer = 0
    all_max, all_min = 0, 0
    for size in sizes:
        max_value, min_value = max(size), min(size)
        all_max = max(max_value, all_max)
        all_min = max(min_value, all_min)
    return all_max * all_min