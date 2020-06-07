import math as mt
A,B,H,W = [int(x) for x in input().split(' ')]

ha = mt.pi * 2 / 12 * H + mt.pi * 2 / 12 * (W/60)
ma = mt.pi * 2 / 60 * W
da = ha-ma

dist = mt.sqrt(A**2 + B**2 - 2*A*B*mt.cos(da))

print(dist)