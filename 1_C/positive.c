#include<stdio.h>


int get_positive_int(void);

int main()
{

	printf("%i\n",get_positive_int());

}

int get_positive_int(void)
{
	int n;

	do
	{

		scanf("%i",&n);

	}
	while(n < 1);

	return n;

}
