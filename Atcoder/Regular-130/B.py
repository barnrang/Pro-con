H,W,C,Q = [int(x) for x in input().split()]

h_dict = {}
v_dict = {}

color_count = {
    x: 0 for x in range(1, C+1)
}

tnc = []

for _ in range(Q):
    tnc.append([int(x) for x in input().split()])


for t,n,c in tnc[::-1]:
    if t == 1:
        if n not in h_dict:
            h_dict[n] = c
            color_count[c] += W - len(v_dict)

    if t == 2:
        if n not in v_dict:
            v_dict[n] = c
            color_count[c] += H - len(h_dict)

print(' '.join([str(color_count[i]) for i in range(1,C+1)]))