N = int(input())
coor = []
for i in range(N):
    x,y = [int(x) for x in input().split()]
    coor.append((x,y))

count = 0
for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            if (coor[i][0] - coor[j][0]) == 0 or (coor[i][0] - coor[k][0]) == 0 or (coor[j][0] - coor[k][0]) == 0:
                if (coor[i][0] - coor[j][0]) != 0 or (coor[i][0] - coor[k][0]) != 0 or (coor[j][0] - coor[k][0]) != 0 :
                    count += 1
                continue
            tana = (coor[i][1] - coor[j][1]) / (coor[i][0] - coor[j][0])
            tanb = (coor[i][1] - coor[k][1]) / (coor[i][0] - coor[k][0])
            tanc = (coor[j][1] - coor[k][1]) / (coor[j][0] - coor[k][0])
            if tana != tanb or tanb != tanc or tana != tanc:
                count += 1  

print(count)

# count = 0

# for i in range(N):
#     for j in range(N):
#         for k in range(N):
#             if i == j or i == k or j == k: continue
#             if (coor[i][0] - coor[j][0]) == 0 or (coor[i][0] - coor[k][0]) == 0:
#                 if (coor[i][0] - coor[j][0]) != 0 or (coor[i][0] - coor[k][0]) != 0:
#                     count += 1
#                 continue
#             tana = (coor[i][1] - coor[j][1]) / (coor[i][0] - coor[j][0])
#             tanb = (coor[i][1] - coor[k][1]) / (coor[i][0] - coor[k][0])
#             if tana != tanb:
#                 count += 1


# print(count)
