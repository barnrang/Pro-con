n = int(input())
s = input()

s = s + '@'

count_same = 1
prev = ''
su = 0
for c in s:
    if prev == c:
        count_same +=1
    else:
        su += (count_same * (count_same - 1))// 2
        count_same = 1
        prev = c

print(su)