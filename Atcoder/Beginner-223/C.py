n = int(input())

AB = []
tot_time = 0
for i in range(n):
    a,b = [int(x) for x in input().split()]
    AB.append((a,b))
    tot_time += a/b

time_use = 0
acc_dist = 0
for a,b in AB:
    time_use += a/b
    acc_dist += a
    if time_use > tot_time / 2:
        acc_dist -= a
        time_use -= a/b
        acc_dist += (tot_time / 2 - time_use) * b
        break


    

    

print(acc_dist)
