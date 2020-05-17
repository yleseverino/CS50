// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 8000;

// Number words in dictionary
unsigned int n_dic = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    char lower[46];

    int i = 0;

    while (word[i] != '\0')
    {
        lower[i] = tolower(word[i]);
        i++;
    }

    lower[i] = '\0';

    int loc = hash(lower);

    if (table[loc] == NULL)
    {
        return false;
    }


    else
    {
        for (node *tmp = table[loc]; tmp != NULL; tmp = tmp->next)
        {
            if (strcmp(tmp->word, lower) == 0)
            {
                return true;
            }
        }
    }

    return false;
}

// Hashes word to a number
// The hash code that I'm going to use is the famouse djb2
unsigned int hash(const char *word)
{

    unsigned int hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // read the file
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        printf("dictionary = NULL");
        return false;
    }

    char str[46];
    int thash;

    int len;

    node *n = NULL;

    node *tmp = NULL;


    //While throught all the words in the file
    while (fgets(str, 46, dic) != NULL)
    {
        // Check if is only a space
        if (isspace(str[0]) != 0)
        {
            break;
        }

        // Check if the last caracter is a space
        len = strlen(str);
        if (isspace(str[len - 1]) != 0)
        {
            str[len - 1] = '\0';
        }

        thash = hash(str);

        tmp = table[thash];

        if (table[thash] == NULL)
        {

            n = malloc(sizeof(node));
            if (n == NULL)
            {
                printf("malloc error");
                return false;
            }

            strcpy(n->word, str);
            n->next = NULL;
            table[thash] = n;
            n_dic++;
        }


        else if (tmp->next == NULL)
        {
            n = malloc(sizeof(node));
            if (n == NULL)
            {
                printf("malloc error");
                return false;
            }

            strcpy(n->word, str);
            n->next = NULL;
            tmp->next = n;
            n_dic++;

        }

        else
        {
            while (tmp->next != NULL)
            {
                tmp = tmp->next;

                if (tmp->next == NULL)
                {
                    n = malloc(sizeof(node));
                    if (n == NULL)
                    {
                        printf("malloc error");
                        return false;
                    }

                    strcpy(n->word, str);
                    n->next = NULL;
                    tmp->next = n;
                    n_dic++;
                    break; //to get out the loop

                }


            }
        }
    }

    fclose(dic);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return n_dic;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }


    return true;
}
