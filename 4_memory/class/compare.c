#include <stdio.h>

int main(void)
{
	char *s = "YLE";
	char *t = "YLE";

	printf("%p\n", s);
	printf("%p\n", t);

	if (*s == *t)
	{
		printf("True\n");
	}
}

