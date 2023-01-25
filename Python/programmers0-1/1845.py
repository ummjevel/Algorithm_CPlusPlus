def solution(nums):
    length = int(len(nums)/2)
    if length > len(set(nums)):
        length = len(set(nums))
    return length