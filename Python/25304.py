total = int(input())
total_cnt = int(input())

for i in range(total_cnt):
    money, cnt = input().split()
    print(total)

    total -= int(money) * int(cnt)


if total == 0:
    print('Yes')
else:
    print('No')