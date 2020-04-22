import math
 
n = int(input())
nodes = []
for i in range(n):
    nodes.append([int(x) for x in input().split(' ')])
 
sums = 0
 
for i in range(n):
    for j in range(n):
        if i != j:
            sums += math.sqrt((nodes[i][0] - nodes[j][0]) ** 2 + (nodes[i][1] - nodes[j][1]) ** 2)
 
print(sums / n)