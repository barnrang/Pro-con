n,m,k = [int(x) for x in input().split(' ')]

t1 = [int(x) for x in input().split(' ')]
t2 = [int(x) for x in input().split(' ')]

s1,s2 = 0,0

s1_s = []

s1_s.append(0)
for i in range(n):
  if s1 + t1[i] > k:
    break
  s1 += t1[i]
  s1_s.append(s1)
  
  
  
p2 = 0
max_b = 0
# print(s1_s, t2)
for i in range(len(s1_s)):
  av = k - s1_s[len(s1_s)-i-1]
  if (p2 >= m): break
  while (s2 + t2[p2]) <= av:
    s2 += t2[p2]
    p2 += 1
    if (p2 >= m): 
        # print(p2)
        break
    

#   print(s1_s[len(s1_s)-i-1], s2)
    
  
  all_b = len(s1_s)-i-1 + p2
  
  if max_b < all_b:
    max_b = all_b

print(max_b)
  