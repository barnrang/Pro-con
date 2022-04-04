
def main():
    h,w = [int(x) for x in input().split()]
    A = []

    for i in range(h):
        A.append([int(x) for x in input().split()])

    for i in range(h):
        for j in range(i+1,h):
            for k in range(w):
                for l in range(k+1, w):
                    if (A[i][k] + A[j][l]) > (A[i][l] + A[j][k]):
                        print('No')
                        return

    print('Yes')
    

    # for i in range(h):
    #     v = 0
    #     for j in range(w):
    #         if A[i][j] >= v:
    #             v = A[i][j]
    #         else:
    #             print('No')
    #             return 

    # for j in range(w):
    #     v = 0
    #     for i in range(h):
    #         if A[i][j] >= v:
    #             v = A[i][j]
    #         else:
    #             print('No')
    #             return 

    # print('Yes')

main()