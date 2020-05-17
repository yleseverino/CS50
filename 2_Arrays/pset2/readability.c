//Author: yleseverino (Github)

//#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

typedef char* string;

int N_words(void);

int N_sentences(void);

void grade(void);

int Igrade(void);

int N_letters(void);

void Test(void);

string input;
int size;

int main(void)
{
    // input = get_string("Text: ");

    Test();

    // input = "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, \"and what is the use of a book,\" thought Alice \"without pictures or conversation?\"";
    // input = "There are more things  in Heaven and Earth, Horatio, than are dreamt of in your philosophy.";
    grade();




}



int N_words(void)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (isspace(input[i]) && (i < size - 1) ? isalpha(input[i + 1]) : 0) //checar 2 espacos
        {
            n++;
        }
    }

    return n + 1;
}

int N_sentences(void)
{
    int n = 0;
    for (int i = 0; i < (size); i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?' || input[i] == ':')
        {
            n++;
        }
    }
    return n;
}

int N_letters(void)
{
    int n = 0;
    for (int i = 0; i < (size); i++)
    {
        if (isalpha(input[i]))
        {
            n++;
        }
    }

    return n;
}


void grade(void)
{
    size = strlen(input);
    int words = N_words();
    int points = N_sentences();
    int letters = N_letters();

    float L = ((float) letters / (float) words) * 100;
    float S = ((float) points / (float) words) * 100;

    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }

}

int Igrade(void)
{
    size = strlen(input);
    int words = N_words();
    int points = N_sentences();
    int letters = N_letters();

    double L = (float)(letters / (float) words) * 100;
    double S = (float)(points / (float) words) * 100;

    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
    {
        return -1;
    }

    else if (index > 16)
    {
        return 17;
    }

    else
    {
        return index;
    }

}

void Test(void)
{
    string inputs[10] = {"One fish. Two fish. Red fish. Blue fish.",
                         "Would you like them here or there? I would not like them here or there. I would not like them anywhere.",
                         "Congratulations! Today is your day. You're off to Great Places! You're off and away!",
                         "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.",
                         "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.",
                         "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, \"and what is the use of a book,\" thought Alice \"without pictures or conversation?\"",
                         "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.",
                         "There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.",
                         "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.",
                         "A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.",
                        };

    int tests[10] = {-1, 2, 3, 5, 7, 8, 8, 9, 10, 17};

    for (int i = 0; i < 10; i++)
    {
        input = inputs[i];
        (Igrade()) == tests[i] ? printf("Correct\n") : printf("Wrong: grade = %i test = %i \n", Igrade(), tests[i]);

    }
}
