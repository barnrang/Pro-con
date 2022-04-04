T = int(input())

for t in range(T):
    n = int(input())

    dices = [int(x) for x in input().split()]
    dices.sort()

    d_count = 0
    for d in dices:
        if d > d_count:
            d_count += 1

    print(f'Case #{t+1}: {d_count}')