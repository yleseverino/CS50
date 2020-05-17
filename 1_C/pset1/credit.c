#include<stdio.h>
//#include<cs50.h>
#include<stdbool.h>

int count(unsigned long long int n);

void card(int n, int initial);

int first_digits(unsigned long long int n);

bool luhn(unsigned long long int n, int digits);

void testcard(unsigned long long int n);

int main(void)
{
    // unsigned long int credit = get_long("Number: ");

    // unsigned long long int credit = 5555555555554444; //MASTERCARD

    unsigned long long int credit = 369421438430814; //INVALIDO

    testcard(credit);
}

int count(unsigned long long int n)
{
    int count = 0;

    while (n != 0)
    {
        n /= 10;

        count++;
    }
    return count;

}

void card(int n, int initial)
{

    if (n == 15 && (initial == 34 || initial == 37))
    {
        printf("AMEX\n");
    }
    else if ((n == 16 || n == 13) && initial / 10 == 4)
    {
        printf("VISA\n");
    }
    else if (n == 16 && (initial == 52 || initial == 53 || initial == 54 || initial == 55 || initial == 51))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

int first_digits(unsigned long long int n)
{
    unsigned long long int first = n;

    int f;

    while (first >= 100)
    {
        first /= 10;
    } 

    f = first;

    return f;
}


bool luhn(unsigned long long int n, int digits)
{
    int odd = 0;
    int even = 0;

    int last;

    for (int i = 1 ; i < digits + 1 ; i++)
    {
            
        last = n % 10;

        if (i % 2 == 0)
        {

        
            last = 2 * last;



            if (last % 10 != 0 || last == 10)
            {  
                even += (last % 10) + (last / 10); //se tiver 2 digitos o numero deve ser separado
            } 	
            else
            {
                even += last;
            }

        }
        else
        {
            odd += last;
        }
        n /= 10;

    }



    even += odd;


    if (even % 10  == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int mypow(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return a * mypow(a, b - 1);
    }
}

void testcard(unsigned long long int n)
{
    int tcount = count(n);

    if (luhn(n, tcount) == true)
    {
        card(tcount, first_digits(n));
    }
    else
    {
        printf("INVALID\n");
    }

}
