X, Y = [int(x) for x in input().split(' ')]
prize = {
    1:300000,
    2:200000,
    3:100000,
}

if (X == 1) and (Y == 1):
    print(1000000)
else:
    s = 0
    if X < 4:
        s += prize[X]
    if Y < 4:
        s += prize[Y]
    print(s)