import cs50

while True:
    n = cs50.get_int("Height: ")
    if n > 0 and n < 9:
        break


for i in range(n):
    for j in range(2 * n + 1):

        if j >= n - 1 - i and j < n:
            print("#", end='')
        elif j == n:
            print("  ", end='')
        elif j < n:
            print(" ", end='')
        elif j > 2*n - i - 1:
            print("#", end='')

    print()