N, K = input().split(' ')
N = int(N)
K = int(K)

H = input().split(' ')
H = [int(x) for x in H if int(x) >= K]
print(len(H))