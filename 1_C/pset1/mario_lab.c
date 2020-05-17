#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: \n");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n ; i++)
    {


        for (int j = 0 ; j < 2 * n + 1 ; j++)
        {

            // adicinando o espaco do meio
            if (j == n)
            {

                printf("  ");
            }
            // adicionando os espacos
            else if (n - j > i + 1)
            {
                printf(" ");
            }
            else if (j > i + n + 1)
            {
                printf("");
            }
            else
            {
                printf("#");
            }

        }
    

        printf("\n");
        
    }

    
}
