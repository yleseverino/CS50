//Author: yleseverino (Github)

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int check(char *text);

void cypher(char *text, char *code);

int main(int argc, char *argv[])
{
    //test

    // argc = 2;

    // argv[1] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    if (argc == 1 || argc > 2)
    {
        printf("error 1\n");
        return 1;
    }

    char *code = argv[1];

    if (!check(code))
    {
        printf("error 2\n");
        return 1;
    }

    char *plaintext = get_string("plaintext: ");
    // char* plaintext = "A";

    cypher(plaintext, code);

    return 0;



}

int check(char *text)
{


    if (strlen(text) != 26) // teste de 26 caracteres
    {
        return 0;
    }

    char a;

    for (int i = 0; i < 26; i++) // teste de alpha
    {
        if (!isalpha(text[i]))
        {
            return 0;
        }

        a = text[i];

        for (int j = 0, n = 0; j < 26 ; j++)
        {
            if (a == text[j])
            {
                n++;
            }

            if (n == 2)
            {
                return 0;
            }
        }
    }

    return 1;
}

void cypher(char *text, char *code)
{
    char cypher[strlen(text) + 1];

    char teste;

    for (int i = 0; i < strlen(text) ; i++)
    {
        if (isupper(text[i])) //65 a 90
        {
            cypher[i] = toupper(code[(int)text[i] - 65]);

        }

        else if (islower(text[i])) //97
        {
            cypher[i] = tolower(code[(int)text[i] - 97]);
        }

        else
        {
            cypher[i] = text[i];
        }
    }

    cypher[strlen(text)] = '\0';

    printf("ciphertext: %s\n", cypher);
}