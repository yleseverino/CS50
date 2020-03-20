#include<stdio.h>
#include<stdbool.h>

int count(unsigned long long int n);

void card(int n, int initial);

int first_digit(unsigned long long int n);

int last_digit(int n);

bool luhn(unsigned long long int n, int digits);

int main (void)
{
    // unsigned long int credit = get_long("Number: ");

    unsigned long long int credit = 4003600000000014;

    printf("%llu",credit % 10);

    printf("%i",count(credit));

    if (luhn(credit,count(credit)) == true)
    {
        card(count(credit),first_digit(credit));
    }
    else
    {
        printf("INVALID\n");
    }

}

int count(unsigned long long int n)
{
    int count = 0;

    while(n!=0)
    {
        n/=10;

        count++;
    }
    return count;

}

void card(int n, int initial)
{
    if (n == 15)
    {
        printf("AMEX\n");
    }
    else if (n == 13)
    {
        printf("VISA\n");
    }
    else if (n == 16 && initial == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("MASTERCARD\n");
    }

}

int first_digit(unsigned long long int n)
{
    unsigned long long int first = n;

    int f;

    while(first >= 10)
    {
        first/=10;
    } 

    f = first;

    return f;
}

int last_digit(int n)
{
    int lastDigit = n % 10;

    return lastDigit;
   
}

bool luhn(unsigned long long int n, int digits)
{
    int odd=0;
    int even=0;


    unsigned long long int last;

  
  
    for (int i = 0 ;i < digits ;i++)
    {
            
        last = n % 10;

        printf("%llu",last);

        if (i % 2 == 0)
        {
            odd += n;
        }
        else
        {
            even += n*2;
        }

        n/=10;

    }

    //printf("%i\n",even);

    //printf("%i\n",odd);

    even += odd;



    if (last_digit(even)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
