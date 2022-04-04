N = int(input())
A = [int(x) for x in input().split(' ')]
all_s = 0
for x in A:
    all_s += x

half_size = all_s / 2.

acc = 0
for x in A:
    prev = acc
    acc += x
    if acc == half_size:
        print(0)
        break
    if acc > half_size:
        s1 = all_s - 2 * prev
        s2 = 2 * acc - all_s
        print(min(s1,s2))
        break