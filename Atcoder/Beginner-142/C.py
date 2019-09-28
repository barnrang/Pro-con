N = int(input())
A = [int(x) for x in input().split(' ')]

order = [(x, i) for i, x in enumerate(A)]
order.sort()
enter_order = [str(x[1] + 1) for x in order]
print((' ').join(enter_order))