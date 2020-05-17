#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// Ensure user ran program with the parameters
	if (argc == 1)
	{
		return 1;
	}
	
	// Open the file .jpeg
	FILE *file = fopen(argv[1],"r");
	if (file == NULL);
	{
		printf("read error\n");
		return 1;
	}

	// Read 3 byres from file
	unsigned char bytes[3];
	fread(bytes, 3, 1, file); // (argument array, number of bytes that I want to read, how many times do I want to read this bytes, the file)

	// Check if bythes are 0xff 0xd8 0xff
	if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
	{
		printf("this is a jpeg\n");
	}
	else
	{
		printf("not jpeg\n");
	}

}

