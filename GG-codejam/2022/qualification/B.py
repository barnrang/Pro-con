T = int(input())


for t in range(T):
    
    req = 1000000
    printer = [
        [int(x) for x in input().split()] for _ in range(3)
    ]

    min_printer = [min([printer[0][i],printer[1][i],printer[2][i]]) for i in range(4)]

    if sum(min_printer) < req:
        print(f'Case #{t+1}: IMPOSSIBLE')

    else:
        out = []
        for p in min_printer:
            if req > p:
                
                out.append(str(p))
                req -= p
            else:
                
                out.append(str(req))
                req = 0

        print(f'Case #{t+1}: ' + ' '.join(out))
