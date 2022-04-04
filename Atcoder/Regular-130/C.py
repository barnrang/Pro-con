a = input()
b = input()

a_dict, b_dict = {x:0 for x in range(1,10)}, {x:0 for x in range(1,10)}

for c in a:
    a_dict[int(c)] += 1

for c in b:
    b_dict[int(c)] += 1

def find_match(num=10):
    for i in range(1,10):
        if a_dict[i] != 0 and b_dict[num-i] != 0:
            return i,num-i



