n = int(input())
st = input()
if n % 2 == 1:
    print('No')
else:
    if st[:n//2] == st[n//2:]:
        print('Yes')
    else:
        print('No')