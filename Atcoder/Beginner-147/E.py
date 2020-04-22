H, W = [int(x) for x in input().split(' ')]

Bs = []
for i in range(H):
    tmp = [int(x) for x in input().split(' ')]
    Bs.append(tmp)

Rs = []
for i in range(H):
    tmp = [int(x) for x in input().split(' ')]
    Rs.append(tmp)

Ds = [[None for _ in range(W)] for __ in range(H)]
Ds[0][0] = (Bs[0][0] - Rs[0][0], Rs[0][0] - Bs[0][0])