M = int(input())
D, C = [], []
for i in range(M):
    d,c = [int(x) for x in input().split(' ')]
    D.append(d)
    C.append(c)

def count_reduce(x, n):
    count = 0

    if n == 1:
        return 0, x
    
    num, left = count_reduce(x, n//2)
    count += 2*num
    if left >= 5:
        count += 2
        left = (2 * left) % 9
    else:
        count += 1
        left = 2 * left

    # Pluse the left over
    if n & 1 == 1:
        if left + x > 9:
            count += 2
            left = (left + x) % 9
        else:
            left = left + x
            count += 1
    return count, left

out_arr = [0 for _ in range(M)]

count = 0
for i in range(M):
    ct, tmp = count_reduce(D[i],C[i])
    count += ct
    out_arr[i] = tmp

lh = out_arr[0]

for i in range(1, M):
    rh = out_arr[i]
    if (lh + rh) > 9:
        count += 2
        lh = (lh + rh) % 9
    else:
        lh = lh + rh
        count += 1


print(count)