import cs50


def main():
    # card = 378282246310005

    # card = 4003600000000014

    card = cs50.get_int("Number: ")
    testcard(card)


def tipo_cartao(n):
    if (int(str(n)[:2]) == 34 or int(str(n)[:2]) == 37) and count(n) == 15:
        print("AMEX")
    elif (int(str(n)[:2]) == 51 or int(str(n)[:2]) == 52 or int(str(n)[:2]) == 53 or int(str(n)[:2]) == 54 or int(str(n)[:2]) == 55) and count(n) == 16:
        print("MASTERCARD")
    elif (int(str(n)[:1]) == 4) and (count(n) == 13 or count(n) == 16):
        print("VISA")
    else:
        print("INVALID")


def cheksumcard(card):
    soma = 0

    temp = card

    # Sum even number from right to left and mutiply by 2
    for i in range(count(card)):

        if i % 2 == 1:

            if count((card % 10) * 2) == 2:

                n = int((card % 10) * 2)
                soma += int(n % 10)
                n = int(n / 10)
                soma += int(n % 10)

            else:

                soma += int((card % 10) * 2)

        card = int(card / 10)

    soma2 = 0

    # Sum odd number from right to left
    for i in range(count(temp)):

        if i % 2 == 0:

            soma2 += temp % 10

        temp = int(temp / 10)

    return soma + soma2


def count(card):
    count = 0
    while (card > 0):
        card = card//10
        count += 1
    return count


def testcard(card):  # Function that test card
    if (cheksumcard(card) % 10) == 0:
        tipo_cartao(card)

    else:
        print("INVALID")


main()
