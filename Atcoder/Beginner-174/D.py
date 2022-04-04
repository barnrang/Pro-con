n = int(input())
s = input()
w_arr = [0]
r_arr = [0]

w_acc = 0
r_acc = 0
for i in range(n):
    if s[i] == 'W':
        w_acc += 1
    else:
        r_acc += 1

    w_arr.append(w_acc)
    r_arr.append(r_acc)


min_r = 999999999999
for i in range(n+1):
    w_1, r_1 = w_arr[i], r_arr[i]
    w_2, r_2 = w_arr[n] - w_arr[i], r_arr[n] - r_arr[i]

    if w_1 >= r_2:
        r = w_1
    else:
        r = r_2

    if r < min_r:
        min_r = r

print(min_r)
