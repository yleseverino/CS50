import cs50


def main():

    string = cs50.get_string("Text: ")

    # string = "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him."

    # string = "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, and what is the use of a book, thought Alice without pictures or conversation?"

    grade(string)

    # print(N_words(string))
    # print(N_sentences(string))


def N_words(string):
    count = 0
    for i in range(len(string) - 1):
        if string[i].isspace() and not(string[i+1].isspace()):
            count += 1

    return count + 1


def N_sentences(string):
    count = 0
    for i in range(len(string)):
        if string[i] == '.' or string[i] == '!' or string[i] == '?':
            count += 1

    return count


def N_letters(string):
    count = 0
    for i in range(len(string)):
        if string[i].isalpha():
            count += 1

    return count


def grade(string):

    words = float(N_words(string))
    points = float(N_sentences(string))
    letters = float(N_letters(string))

    L = float(letters / words) * 100
    S = float(points / words) * 100

    print(words)
    print(points)
    print(letters)

    index = round((0.0588 * L) - (0.296 * S) - 15.8)

    if index < 1:
        print("Before Grade 1")

    elif index > 16:
        print("Grade 16+")

    else:
        print(f"Grade {index}")


main()