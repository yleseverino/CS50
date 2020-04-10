#include <stdio.h>
#include <string.h>


typedef struct
{
	char *name;
	char *number;
}
person;

int main(void)
{
	person people[4];

	people[0].name = "EMMA";
	people[0].number = "617-555-0100";

	people[1].name = "ROFRIGO";
	people[1].number = "617-555-0101";

	people[2].name = "BRIAN";
	people[2].name = "617-555-102";

	people[3].name = "DAVID";
	people[3].number = "617-555-0103";

	for (int i = 0; i < 4; i++)
	{
		if (strcasecmp(people[i].name, "EMMA") == 0)
		{
			printf("%s\n",people[i].number);
			return 0;
		}
	}
	printf("Not Founded");
	return 1;
}

