import math

A,B,C,D = [int(x) for x in input().split(' ')]
t = math.ceil(C / B)
s = math.ceil(A / D)

if t > s:
    print('No')
else:
    print('Yes')