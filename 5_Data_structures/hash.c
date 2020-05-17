#include <stdio.h>
#include <stdlib.h>

unsigned long hash(const unsigned char *str);

int main (int argc, char *argv[])
{
	if (argc == 1)
	{
		return 1;
	}


	printf("%lu\n",hash(argv[1]));
	printf("%lu\n",hash(argv[1]) % 10000);
}

unsigned int hash(const unsigned char *str)
{
	unsigned int hash = 5381;
        int c;

        while (c = *str++) hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
}


