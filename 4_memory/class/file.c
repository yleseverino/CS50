#include <stdio.h>

int main(void)
{
	FILE *file = fopen("phonebook.csv","a");

	char *name = "Yle";
	char *number = "66641364";

	fprintf(file,"%s,%s\n", name, number);

	fclose(file);

}
