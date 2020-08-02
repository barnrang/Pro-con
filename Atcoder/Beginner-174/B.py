k = int(input())

r = 7
count = 1
found = 0
for i in range(k):
    if r % k == 0:
        print(count)
        found = 1
        break
    r = (10 * r + 7) % k
    count += 1
if found == 0:
    print(-1)
