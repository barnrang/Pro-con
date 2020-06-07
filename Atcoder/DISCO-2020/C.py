H, W, K = [int(x) for x in input().split(' ')]
tab = []
for i in range(H):
    tab.append(input())

have_st = []

def find_pos(row):
    arr = []
    for idx, ch in enumerate(row):
        if ch == '#':
            arr.append(idx)

    return arr

for i in range(H):
    if '#' in tab[i]:
        have_st.append(i)

prev_len = 0
rec_grid = []
st_c = 0
st_r = 0
for idx, row_idx in enumerate(have_st):
    row = tab[row_idx]
    pos = find_pos(row)
    if len(have_st) == 1:
        for c, i in enumerate(pos):
            if c == len(pos) - 1:
                ed_r = row_idx
                ed_c = W-1
                rec_grid.append(((0,st_c), (H-1, ed_c)))
            else:
                ed_r = row_idx
                ed_c = i
                rec_grid.append(((0,st_c), (H-1, ed_c)))
                st_c = i + 1
        break
    if idx != len(have_st) - 1:
        for c, i in enumerate(pos):
            if c == len(pos) - 1:
                ed_r = row_idx
                ed_c = W-1
                rec_grid.append(((st_r,st_c), (ed_r, ed_c)))
            else:
                ed_r = row_idx
                ed_c = i
                rec_grid.append(((st_r,st_c), (ed_r, ed_c)))
                st_c = i + 1

        pass
    else:
        for c, i in enumerate(pos):
            if c == len(pos) - 1:
                ed_r = H-1
                ed_c = W-1
                rec_grid.append(((st_r,st_c), (ed_r, ed_c)))
            else:
                ed_r = H-1
                ed_c = i
                rec_grid.append(((st_r,st_c), (ed_r, ed_c)))
                st_c = i + 1


    st_r = row_idx + 1
    st_c = 0

out_arr = [[None for _ in range(W)] for __ in range(H)]
# print(rec_grid)
for idx, grids in enumerate(rec_grid):
    (st_r, st_c), (ed_r, ed_c) = grids
    for i in range(st_r, ed_r+1):
        for j in range(st_c, ed_c+1):
            out_arr[i][j] = str(idx + 1)

for row in out_arr:
    print((' ').join(row))
