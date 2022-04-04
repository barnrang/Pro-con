import random

T = int(input())

for t in range(T):
    number_pass = 0
    n,k = [int(x) for x in input().split()]
    r, p = [int(x) for x in input().split()]

    number_pass += p

    random_list = [x for x in range(1, 1+n, 1) if x != r]
    random.shuffle(random_list)

    random_choice = min(8000, len(random_list))

    for room in random_list[:random_choice]:
        print(f'T {room}',flush=True)
        r, p = [int(x) for x in input().split()]
        number_pass += p

    guess = int(number_pass / random_choice * n / 2)
    print(f'E {guess}',flush=True)
