#include <stdio.h>

typedef char* string;

int main(void)
{
	string names[4];
	names[0] = "YLE";
	names[1] = "JULIA";
	names[2] = "ADELAIDE";
	names[3] = "EDUARDO";

	printf("%c%c%c\n",names[0][0],names[0][1],names[0][2]);
}
