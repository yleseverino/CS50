#include <stdio.h>

typedef char* string;

int main(int argc,string argv[])
{
	if (argc == 3)
	{
		printf("hello, %s\n",argv[2]);
	}
	else
	{
		printf("hello, world\n");
	}

}

