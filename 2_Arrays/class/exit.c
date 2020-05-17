#include <stdio.h>

typedef char* string;

int main (int argc, string argv[])
{
	if (argc == 1)
	{
		printf("missing command-line argument\n");
		return 1;
	}
	printf("Hi, %s\n",argv[1]);
	return 0;
}
