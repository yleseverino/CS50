#include<stdio.h>
#include<unistd.h>


int main(void)
{
	unsigned long long int a = 400360000000001;

	for (int i =1;i<50;i++)
	{
		a *=i;
		sleep(1);
		printf("%llu\n",a);

	}
}


